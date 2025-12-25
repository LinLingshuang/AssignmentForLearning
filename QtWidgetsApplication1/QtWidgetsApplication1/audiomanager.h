#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <QObject>
#include <QTimer>
#include <QMap>
#include <QStringList>
#include <QPointer>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>

class AudioPlayer : public QObject
{
    Q_OBJECT

public:
    explicit AudioPlayer(QObject* parent = nullptr);
    ~AudioPlayer();

    // 音效管理
    void loadSoundEffect(const QString& key, const QString& path);
    void playSoundEffect(const QString& key);
    bool isSoundEffectLoaded(const QString& key) const;
    QStringList getLoadedSoundEffects() const;
    void clearSoundEffects();

    // 背景音乐管理
    void playBgm(const QString& path, int durationMs = 5000);
    void pauseBgm();
    void resumeBgm();
    void stopBgm();

    // 音量控制
    void setVolume(float volume);  // 0.0 到 1.0
    float getVolume() const;
    void setSoundEffectVolume(float volume);  // 0.0 到 1.0
    float getSoundEffectVolume() const;
    void setMusicVolume(float volume);  // 0.0 到 1.0
    float getMusicVolume() const;

    // 工具函数
    void testAllAudioFiles();

    void setVolume(int volume) { setVolume(static_cast<float>(volume) / 100.0f); }

private slots:
    void onBgmLoop();
    void onSoundEffectFinished();
    
private:
    // 私有辅助函数
    QString convertQrcPath(const QString& path) const;
    QUrl toMediaUrl(const QString& path) const;

    // 成员变量
    QPointer<QMediaPlayer> m_bgmPlayer;       // 背景音乐播放器
    QPointer<QAudioOutput> m_bgmAudioOutput;  // 背景音乐音频输出
    QTimer* m_bgmTimer;                       // 背景音乐循环定时器
    QMap<QString, QString> m_soundMap;        // 音效映射表
    bool m_isBgmPlaying;                      // BGM播放状态
    int m_bgmDuration;                        // BGM时长（毫秒）
    QString m_bgmPath;                        // 当前BGM路径
    float m_volume;                           // 总音量（0.0-1.0）
    float m_soundEffectVolume;                // 音效音量（0.0-1.0）
    float m_musicVolume;                      // 音乐音量（0.0-1.0）
};

#endif // AUDIOMANAGER_H
