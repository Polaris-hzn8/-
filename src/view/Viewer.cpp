///****************************************************************************
/// @Author    : Polaris-hzn8
/// @Mail      : 3453851623@qq.com
///****************************************************************************

#include "Viewer.h"

Viewer* Viewer::s_instance = nullptr;

Viewer* Viewer::getInstance()
{
    if (!s_instance) {
        s_instance = new Viewer();
    }
    return s_instance;
}

Viewer::Viewer()
{
}

Viewer::~Viewer()
{
}

void Viewer::playEntryAnimation()
{
    // 故事内容
    std::vector<std::string> sentences = {
        "**********************************************************************************",
        "                               都市浮生日记的故事",
        "**********************************************************************************",
        "    您扮演一位从外地到城市谋生的青年，一开始您只有2000元，并且还欠村长（一个流氓头",
        "子）5500元的债务。这些债务每天的利息高达10%，如果不及时还清，村长会叫在市里的老乡们",
        "来扁您，您可能会牺牲在市区街头。您决定在市区地铁各黑市倒卖各种物品来发财致富，不仅还",
        "掉债务而且还要荣登富人排行榜。",
        "    您只能在城市呆100天，每次奔走一个黑市算1天，刚开始您租的房子只能放100个东西。您",
        "会在市区遭遇到各种事件、您需要与流氓、小偷、凶手、贪官、骗子等斗智斗勇，还需要在市区",
        "恶劣的自然环境下设法生存下来。",
        "    您将体验在城市卖盗版VCD和走私汽车的刺激、以及我们这个时代才有的搞笑事件。     ",
        "**********************************************************************************"
    };
    for (int i = 0; i < sentences.size(); ++i) {
        if (i < 3 || i == (sentences.size() - 1)) {
            std::cout << sentences[i] << std::endl;
        } else {
            playTypeWrite(sentences[i]);
        }
    }
}

void Viewer::playTypeWrite(std::string line)
{
    float speed = 10; // ms
    for (int i = 0; i < line.length(); ++i) {
        std::cout << line[i];
        if (line[i] == ' ') {
            continue;
        } else {
            Sleep(speed);
        }
    }
    std::cout << std::endl;
}
