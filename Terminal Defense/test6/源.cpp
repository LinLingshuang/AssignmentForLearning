#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QMessageBox>
#include <QFont>
#include <QPalette>
#include <QKeyEvent>

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于time()

// Windows特定的头文件暂时注释掉，因为Qt是跨平台的
// #include <windows.h>
// #include <conio.h>

using namespace std;

// 保留你的枚举和类定义，但暂时注释掉控制台相关的函数
/*
enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    BrightBlue = 9,
    BrightGreen = 10,
    BrightCyan = 11,
    BrightRed = 12,
    BrightMagenta = 13,
    BrightYellow = 14,
    BrightWhite = 15
};

void setColor(int textColor, int bgColor = Black) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void resetColor() {
    setColor(White, Black);
}

//---------------------------------
void reloading() {

    system("cls");
    for (int i = 0; i < 13; i++) {

        for (int j = 0; j < 25; j++) {
            if ((j + i < 13) || (j + i > 20)) {
                cout << " ";
            }
            else {
                cout << "*";
            }

        }
        cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
*/

// 保留你的类定义，暂时注释掉实现
/*
class towerchoicingInput {
public:
    char getChar() {
        if (_kbhit()) {
            return _getch();
        }
        return 0;
    }
};

class monsterhome {
public:
    monsterhome() {
        x = 0;
        y = 0;
    }
    monsterhome(int xx, int yy) {
        x = xx;
        y = yy;
    }
    monsterhome(monsterhome& moshome) {
        x = moshome.x;
        y = moshome.y;
    }
    int getx() { return x; }
    int gety() { return y; }

    ~monsterhome() {}
private:
    int x;
    int y;
};

class playerhome {
public:
    playerhome() {
        x = 0;
        y = 0;
    }
    playerhome(int xx, int yy) {
        x = xx;
        y = yy;
    }
    playerhome(playerhome& home) {
        x = home.x;
        y = home.y;
    }
    int getx() { return x; }
    int gety() { return y; }

    ~playerhome() {}
private:
    int x;
    int y;
};

class block {
public:
    block() {
        x = 0;
        y = 0;
    }
    block(int xx, int yy) {
        x = xx;
        y = yy;
    }
    block(const block& b) {
        x = b.x;
        y = b.y;
    }
    int getx() { return x; }
    int gety() { return y; }

    void createblock(int xm, int ym) {
        x = xm;
        y = ym;
    }

    ~block() {}
private:
    int x;
    int y;
};

class monster {
public:
    monster() {
        x = 0;
        y = 0;
        playerhome ph;
        monsterhome mh;
    }
    monster(int xx, int yy, monsterhome mhh, playerhome phh, block bss[10]) {
        x = xx;
        y = yy;
        for (int i = 0; i < 10; i++) {
            bs[i] = bss[i];
        }
        ph = phh;
        mh = mhh;
    }
    monster(const monster& mos) {
        x = mos.x;
        y = mos.y;
        for (int i = 0; i < 10; i++) {
            bs[i] = mos.bs[i];
        }
        ph = mos.ph;
        mh = mos.mh;
    }
    int getx() { return x; }
    int gety() { return y; }

    void monsterinhome(playerhome ph) {
        if (x == ph.getx() && y == ph.gety()) {
            // 在Qt中这里会显示对话框
        }
    }

    void walk(playerhome ph, block bs[10]) {
        // 移动逻辑暂时保留
    }

    void create(monsterhome mh, playerhome ph) {
        x = mh.getx();
        y = mh.gety();
        ph = ph;
    }

    void changexy() {
        int random_numx = rand() % 18 + 1;
        int random_numy = rand() % 8 + 1;
        x = random_numx;
        y = random_numy;
    }

    ~monster() {}
private:
    int x;
    int y;
    block bs[10];
    playerhome ph;
    monsterhome mh;
};

class map {
public:
    map(monster mm[5], block ass[10], playerhome phm, monsterhome mhm) {
        for (int i = 0; i < 5; i++) {
            m[i] = mm[i];
        }
        for (int i = 0; i < 10; i++) {
            as[i] = ass[i];
        }
        ph = phm;
        mh = mhm;
    }
    map() {}

    map(map& M) {
        for (int i = 0; i < 5; i++) {
            m[i] = M.m[i];
        }
        for (int i = 0; i < 10; i++) {
            as[i] = M.as[i];
        }
        ph = M.ph;
        mh = M.mh;
    }

    void showmap(monster m[5], block bs[10], monsterhome mh1, playerhome ph1) {
        // 在Qt中这里会绘制游戏地图
    }

    ~map() {}

private:
    int length = 20;
    int weight = 10;
    block as[10];
    monster m[5];
    playerhome ph;
    monsterhome mh;
};

int testcoin = 0;

class towermiue {
public:
    towermiue() {}
    towermiue(char choicingg, char shoppingg) {
        choicing = choicingg;
        shopping = shoppingg;
    }
    towermiue(towermiue& tm) {
        choicing = tm.choicing;
        shopping = tm.shopping;
    }

    void showtowermiue() {
        // 在Qt中这里会显示炮塔菜单
    }

    void choicetower() {
        // 在Qt中这里会处理炮塔选择
    }

    ~towermiue() {}

private:
    char choicing = 0;
    char shopping = 0;
};
*/

// MainWindow类实现
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr) : QMainWindow(parent)
    {
        // 设置窗口属性
        setWindowTitle("Terminal Defense - QT Version");
        setFixedSize(800, 600);

        // 创建中央部件
        centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        // 创建主布局
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(30);
        mainLayout->setContentsMargins(60,60,60,60);

        // 初始化主菜单
        setupMainMenu();
    }

    ~MainWindow() {}

private slots:
    void onStartClicked()
    {
        QMessageBox::information(this, "开始游戏",
            "游戏开始功能正在开发中...\n\n"
            "这里将显示游戏地图和怪物。");

        // 后续在这里切换到游戏界面
        // setupGameScreen();
    }

    void onHelpClicked()
    {
        setupHelpScreen();
    }

    void onQuitClicked()
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "确认退出",
            "确定要退出游戏吗？",
            QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            QApplication::quit();
        }
    }

    void onBackClicked()
    {
        setupMainMenu();
    }

private:
    void setupMainMenu()
    {
        // 清除现有布局内容
        QLayoutItem* child;
        while ((child = mainLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }

        // 创建标题
        titleLabel = new QLabel("Terminal Defense", centralWidget);
        QFont titleFont("Arial", 24, QFont::Bold);
        titleLabel->setFont(titleFont);

        // 设置标题颜色（蓝色）
        QPalette palette = titleLabel->palette();
        palette.setColor(QPalette::WindowText, QColor(0, 120, 215)); // 蓝色
        titleLabel->setPalette(palette);
        titleLabel->setAlignment(Qt::AlignCenter);

        // 创建按钮
        startButton = new QPushButton("开始游戏 (S)", centralWidget);
        helpButton = new QPushButton("玩法说明 (H)", centralWidget);
        quitButton = new QPushButton("退出游戏 (Q)", centralWidget);

        // 设置按钮样式
        QString buttonStyle =
            "QPushButton {"
            "    background-color: #4CAF50;"
            "    border: none;"
            "    color: white;"
            "    padding: 15px 32px;"
            "    text-align: center;"
            "    text-decoration: none;"
            "    font-size: 16px;"
            "    margin: 4px 2px;"
            "    border-radius: 8px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #45a049;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #3d8b40;"
            "}";

        startButton->setStyleSheet(buttonStyle);
        helpButton->setStyleSheet(buttonStyle);

        // 退出按钮用红色
        QString quitButtonStyle =
            "QPushButton {"
            "    background-color: #f44336;"
            "    border: none;"
            "    color: white;"
            "    padding: 15px 32px;"
            "    text-align: center;"
            "    text-decoration: none;"
            "    font-size: 16px;"
            "    margin: 4px 2px;"
            "    border-radius: 8px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #da190b;"
            "}"
            "QPushButton:pressed {"
            "    background-color: #b30c00;"
            "}";
        quitButton->setStyleSheet(quitButtonStyle);

        // 设置按钮大小
        startButton->setMinimumHeight(50);
        helpButton->setMinimumHeight(50);
        quitButton->setMinimumHeight(50);

        // 连接信号和槽
        connect(startButton, &QPushButton::clicked, this, &MainWindow::onStartClicked);
        connect(helpButton, &QPushButton::clicked, this, &MainWindow::onHelpClicked);
        connect(quitButton, &QPushButton::clicked, this, &MainWindow::onQuitClicked);

        // 添加控件到布局
        mainLayout->addWidget(titleLabel);
        mainLayout->addSpacing(40);

        // 创建按钮布局
        QVBoxLayout* buttonLayout = new QVBoxLayout();
        buttonLayout->setSpacing(15);
        buttonLayout->addWidget(startButton);
        buttonLayout->addWidget(helpButton);
        buttonLayout->addWidget(quitButton);

        mainLayout->addLayout(buttonLayout);
        mainLayout->addStretch();
    }

    void setupHelpScreen()
    {
        // 清除现有布局内容
        QLayoutItem* child;
        while ((child = mainLayout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }

        // 创建帮助界面标题
        QLabel* helpTitle = new QLabel("玩法说明", centralWidget);
        QFont titleFont("Arial", 20, QFont::Bold);
        helpTitle->setFont(titleFont);
        helpTitle->setAlignment(Qt::AlignCenter);

        // 创建帮助文本
        helpText = new QLabel(centralWidget);
        helpText->setText(
            "当前是测试版本，暂无详细教程说明。\n\n"
            "游戏基本规则：\n"
            "• 防止怪物到达你的基地\n"
            "• 使用障碍物阻挡怪物\n"
            "• 赚取金币升级防御\n\n"
            "更多功能开发中..."
        );
        helpText->setAlignment(Qt::AlignCenter);
        helpText->setWordWrap(true);

        // 创建返回按钮
        backButton = new QPushButton("返回主菜单 (B)", centralWidget);

        // 设置返回按钮样式
        QString backButtonStyle =
            "QPushButton {"
            "    background-color: #008CBA;"
            "    border: none;"
            "    color: white;"
            "    padding: 15px 32px;"
            "    text-align: center;"
            "    text-decoration: none;"
            "    font-size: 16px;"
            "    margin: 4px 2px;"
            "    border-radius: 8px;"
            "}"
            "QPushButton:hover {"
            "    background-color: #007B9A;"
            "}";
        backButton->setStyleSheet(backButtonStyle);
        backButton->setMinimumHeight(50);

        // 连接返回按钮
        connect(backButton, &QPushButton::clicked, this, &MainWindow::onBackClicked);

        // 添加到布局
        mainLayout->addWidget(helpTitle);
        mainLayout->addSpacing(30);
        mainLayout->addWidget(helpText);
        mainLayout->addSpacing(30);
        mainLayout->addWidget(backButton);
        mainLayout->addStretch();
    }

    // 界面组件
    QWidget* centralWidget;
    QVBoxLayout* mainLayout;

    // 主菜单组件
    QLabel* titleLabel;
    QPushButton* startButton;
    QPushButton* helpButton;
    QPushButton* quitButton;

    // 帮助界面组件
    QLabel* helpText;
    QPushButton* backButton;
};

// 主函数
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // 设置应用程序信息
    app.setApplicationName("Terminal Defense");
    app.setApplicationVersion("1.0");

    MainWindow window;
    window.show();

    return app.exec();
}

// 需要包含moc文件以确保信号槽机制工作
