#include "audiomanager.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDirIterator>
#include <QFileInfo>
#include <QAudioOutput>
#include <QUrl>

// 构造函数实现
AudioPlayer::AudioPlayer(QObject* parent)
    : QObject(parent)
    , m_bgmPlayer(nullptr)
    , m_bgmAudioOutput(nullptr)
    , m_bgmTimer(new QTimer(this))
    , m_isBgmPlaying(false)
    , m_bgmDuration(5000) // 默认BGM时长5秒
    , m_volume(1.0f)     // 默认总音量100%
    , m_soundEffectVolume(1.0f) // 默认音效音量100%
    , m_musicVolume(1.0f) // 默认音乐音量100%
{
    // 配置BGM循环定时器为单次触发
    m_bgmTimer->setSingleShot(true);
    // 绑定定时器超时信号到循环播放槽函数
    connect(m_bgmTimer, &QTimer::timeout, this, &AudioPlayer::onBgmLoop);
    
    // 初始化BGM音频输出
    m_bgmAudioOutput = new QAudioOutput(this);
    // 设置初始音量
    m_bgmAudioOutput->setVolume(m_musicVolume * m_volume);
    
    // 初始化BGM播放器
    m_bgmPlayer = new QMediaPlayer(this);
    // 将播放器与音频输出关联
    m_bgmPlayer->setAudioOutput(m_bgmAudioOutput);
    m_bgmPlayer->setLoops(QMediaPlayer::Infinite);
}

// 析构函数实现，清理资源
AudioPlayer::~AudioPlayer()
{
    // 停止所有播放
    stopBgm();
    
    // 清理定时器
    if (m_bgmTimer) {
        m_bgmTimer->stop();
        delete m_bgmTimer;
    }
    
    // 清理BGM播放器和音频输出
    if (m_bgmPlayer) {
        m_bgmPlayer->stop();
        delete m_bgmPlayer;
    }
    
    if (m_bgmAudioOutput) {
        delete m_bgmAudioOutput;
    }
}

// 预加载音效实现
void AudioPlayer::loadSoundEffect(const QString& key, const QString& path)
{
    // 校验参数合法性
    if (key.isEmpty() || path.isEmpty()) {
        qWarning() << "[AudioPlayer] 错误：音效标识或文件路径为空！";
        return;
    }

    // 校验文件格式（仅支持WAV）
    if (!path.endsWith(".wav", Qt::CaseInsensitive)) {
        qWarning() << "[AudioPlayer] 错误：仅支持WAV格式音效，当前文件：" << path;
        return;
    }

    // 验证文件是否存在
    QString realPath = convertQrcPath(path);
    QFile fileCheck(realPath);
    if (!fileCheck.exists()) {
        qWarning() << "[AudioPlayer] 错误：文件不存在：" << path << "（实际路径：" << realPath << "）";
        return;
    }

    // 存储音效标识与路径的映射
    m_soundMap[key] = path;
    qDebug() << "[AudioPlayer] 音效预加载成功：" << key << "->" << path;
}

// 播放单次音效实现
void AudioPlayer::playSoundEffect(const QString& key)
{
    // 校验音效是否已预加载
    if (!m_soundMap.contains(key)) {
        qWarning() << "[AudioPlayer] 错误：未加载该音效，标识：" << key;
        return;
    }

    // 获取音效文件路径
    QString path = m_soundMap[key];
    
    // 创建QSoundEffect实例播放音效
    QSoundEffect* soundEffect = new QSoundEffect(this);
    soundEffect->setSource(toMediaUrl(path));
    soundEffect->setVolume(m_soundEffectVolume * m_volume);
    
    // 连接播放完成信号，自动清理资源
    connect(soundEffect, &QSoundEffect::playingChanged, this, &AudioPlayer::onSoundEffectFinished);
    
    // 播放音效
    soundEffect->play();
    
    qDebug() << "[AudioPlayer] 播放音效：" << key;
}

// 播放背景音乐（循环）实现
void AudioPlayer::playBgm(const QString& path, int durationMs)
{
    // 验证文件是否存在
    QString realPath = convertQrcPath(path);
    QFile fileCheck(realPath);
    if (!fileCheck.exists()) {
        qWarning() << "[AudioPlayer] 错误：BGM文件不存在：" << path << "（实际路径：" << realPath << "）";
        return;
    }

    // 停止当前BGM播放和定时器
    if (m_bgmPlayer) {
        m_bgmPlayer->stop();
    }
    m_bgmTimer->stop();
    
    // 存储BGM路径和时长
    m_bgmPath = path;
    m_bgmDuration = qMax(1000, durationMs); // 确保最少1秒
    m_isBgmPlaying = true;
    
    // 设置媒体源并播放
    if (m_bgmPlayer) {
        m_bgmPlayer->setSource(toMediaUrl(path));
        m_bgmPlayer->setLoops(QMediaPlayer::Infinite);
        m_bgmPlayer->play();
        qDebug() << "[AudioPlayer] BGM开始循环播放：" << path << "，时长：" << m_bgmDuration << "ms";
    }
}

// 继续播放背景音乐实现
void AudioPlayer::resumeBgm()
{
    if (m_bgmPlayer && !m_isBgmPlaying && !m_bgmPath.isEmpty()) {
        m_bgmPlayer->play();
        m_isBgmPlaying = true;
        // 确保定时器在运行
        if (!m_bgmTimer->isActive()) {
            m_bgmTimer->start(m_bgmDuration);
        }
        qDebug() << "[AudioPlayer] BGM已恢复播放";
    }
}

// 暂停背景音乐实现
void AudioPlayer::pauseBgm()
{
    if (m_bgmPlayer && m_isBgmPlaying) {
        m_bgmPlayer->pause();
        m_isBgmPlaying = false;
        m_bgmTimer->stop();
        qDebug() << "[AudioPlayer] BGM已暂停";
    }
}

// 停止背景音乐实现
void AudioPlayer::stopBgm()
{
    if (m_bgmPlayer) {
        m_bgmPlayer->stop();
    }
    m_bgmTimer->stop();
    m_isBgmPlaying = false;
    m_bgmPath.clear();
    m_bgmDuration = 5000; // 重置为默认值
    qDebug() << "[AudioPlayer] BGM已停止";
}

// 检查音效是否已加载
bool AudioPlayer::isSoundEffectLoaded(const QString& key) const
{
    return m_soundMap.contains(key);
}

// 获取所有已加载音效的标识
QStringList AudioPlayer::getLoadedSoundEffects() const
{
    return m_soundMap.keys();
}

// 清理所有已加载音效
void AudioPlayer::clearSoundEffects()
{
    m_soundMap.clear();
    qDebug() << "[AudioPlayer] 已清除所有音效";
}



// BGM循环触发的槽函数实现
void AudioPlayer::onBgmLoop()
{
    // 仅当BGM处于播放状态且路径有效时，重新播放
    if (m_isBgmPlaying && !m_bgmPath.isEmpty() && m_bgmPlayer) {
        m_bgmPlayer->setSource(toMediaUrl(m_bgmPath));
        m_bgmPlayer->play();
        // 重启循环定时器
        m_bgmTimer->start(m_bgmDuration);
        qDebug() << "[AudioPlayer] BGM循环播放";
    }
}

// 音效播放完成槽函数实现
void AudioPlayer::onSoundEffectFinished()
{
    QSoundEffect* soundEffect = qobject_cast<QSoundEffect*>(sender());
    // 仅在音效不再播放时清理，避免刚开始播放就被删除
    if (soundEffect && !soundEffect->isPlaying()) {
        soundEffect->deleteLater();
    }
}

QString AudioPlayer::convertQrcPath(const QString& path) const
{
    QString result = path;

    // 统一路径格式
    if (result.startsWith("::/")) {
        result = ":" + result.mid(2); // ::/music/... -> :/music/...
    }
    else if (result.startsWith("qrc:/")) {
        result = ":" + result.mid(4); // qrc:/music/... -> :/music/...
    }

    return result;
}

QUrl AudioPlayer::toMediaUrl(const QString& path) const
{
    QString normalized = convertQrcPath(path);
    if (normalized.startsWith(":/")) {
        return QUrl("qrc" + normalized); // qrc:/...
    }
    return QUrl::fromLocalFile(normalized);
}


// 测试所有音频文件
void AudioPlayer::testAllAudioFiles()
{
    qDebug() << "=== 音频文件测试开始 ===";

    // 测试已加载的音效
    qDebug() << "已加载的音效 (" << m_soundMap.size() << "个):";
    for (auto it = m_soundMap.constBegin(); it != m_soundMap.constEnd(); ++it) {
        QString realPath = convertQrcPath(it.value());
        QFile file(realPath);
        qDebug() << "  " << it.key() << "->" << it.value()
            << (file.exists() ? "[存在]" : "[不存在]")
            << "大小:" << (file.exists() ? QString::number(file.size()) + "字节" : "N/A");
    }

    // 测试BGM文件
    if (!m_bgmPath.isEmpty()) {
        QString realPath = convertQrcPath(m_bgmPath);
        QFile file(realPath);
        qDebug() << "BGM文件:" << m_bgmPath
            << (file.exists() ? "[存在]" : "[不存在]");
    }

    // 列出QRC资源 - 修复版本
    qDebug() << "QRC资源列表 (WAV文件):";
    try {
        QDirIterator it(":", QDirIterator::Subdirectories);
        int wavCount = 0;
        while (it.hasNext()) {
            QString filePath = it.next();
            if (filePath.endsWith(".wav", Qt::CaseInsensitive)) {
                qDebug() << "  " << filePath;
                wavCount++;
            }
        }
        qDebug() << "找到" << wavCount << "个WAV文件";
    }
    catch (...) {
        qWarning() << "遍历QRC资源时出错";
    }

    qDebug() << "=== 音频文件测试结束 ===";
}

// 设置总音量
void AudioPlayer::setVolume(float volume)
{
    m_volume = qBound(0.0f, volume, 1.0f);
    qDebug() << "[AudioPlayer] 总音量设置为：" << m_volume;
    
    // 更新BGM音频输出的音量
    if (m_bgmAudioOutput) {
        m_bgmAudioOutput->setVolume(m_musicVolume * m_volume);
    }
}

// 获取当前总音量
float AudioPlayer::getVolume() const
{
    return m_volume;
}

// 设置音效音量
void AudioPlayer::setSoundEffectVolume(float volume)
{
    m_soundEffectVolume = qBound(0.0f, volume, 1.0f);
    qDebug() << "[AudioPlayer] 音效音量设置为：" << m_soundEffectVolume;
    // 音效音量在播放时动态应用
}

// 获取当前音效音量
float AudioPlayer::getSoundEffectVolume() const
{
    return m_soundEffectVolume;
}

// 设置音乐音量
void AudioPlayer::setMusicVolume(float volume)
{
    m_musicVolume = qBound(0.0f, volume, 1.0f);
    qDebug() << "[AudioPlayer] 音乐音量设置为：" << m_musicVolume;
    
    // 更新BGM音频输出的音量
    if (m_bgmAudioOutput) {
        m_bgmAudioOutput->setVolume(m_musicVolume * m_volume);
    }
}

// 获取当前音乐音量
float AudioPlayer::getMusicVolume() const
{
    return m_musicVolume;
}

