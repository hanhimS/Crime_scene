#include <bangtal>

#include <functional>
#include <iostream>
#include <string>

using namespace bangtal;
using namespace std;


int main() {
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

    auto back_sound1 = Sound::create("Sounds/기본 배경음악.mp3");
    auto back_sound2 = Sound::create("Sounds/읽기장읽은후 배경음악.mp3");
    auto door_sound = Sound::create("Sounds/문 여는 소리.mp3");
    auto paper_sound = Sound::create("Sounds/종이넘기기 효과음.mp3");
    auto hint_sound = Sound::create("Sounds/힌트생성 효과음.mp3");
    back_sound1->play(true);


    auto tutorial1 = Scene::create("튜토리얼1", "Images/튜토리얼/튜토리얼1.png");
    auto tutorial2 = Scene::create("튜토리얼2", "Images/튜토리얼/튜토리얼2.png");
    auto tutorial3 = Scene::create("튜토리얼3", "Images/튜토리얼/튜토리얼3.png");
    auto tutorial4 = Scene::create("튜토리얼4", "Images/튜토리얼/튜토리얼4.png");
    auto tutorial5 = Scene::create("튜토리얼5", "Images/튜토리얼/튜토리얼5.png");
    auto tutorial6_1 = Scene::create("튜토리얼6-1", "Images/튜토리얼/튜토리얼6-1.png");
    auto tutorial6_2 = Scene::create("튜토리얼6-2", "Images/튜토리얼/튜토리얼6-2.png");
    auto tutorial7 = Scene::create("튜토리얼7", "Images/튜토리얼/튜토리얼7.png");
    auto tutorial8 = Scene::create("튜토리얼8", "Images/튜토리얼/튜토리얼8.png");
    auto tutorial9 = Scene::create("튜토리얼9", "Images/튜토리얼/튜토리얼9.png");
    auto tutorial10 = Scene::create("튜토리얼10", "Images/튜토리얼/튜토리얼10.png");
    auto caution = Scene::create("유의사항", "Images/튜토리얼/유의사항.png");



    auto lobby = Scene::create("로비", "Images/호텔 복도.jpg");
    auto room804 = Scene::create("804호(교수방)", "Images/호텔 방.jpg");
    auto room805 = Scene::create("805호(박사방)", "Images/호텔 방.jpg");
    auto room806 = Scene::create("806호(석사방)", "Images/호텔 방.jpg");
    auto room807 = Scene::create("807호(학부연구생방)", "Images/호텔 방.jpg");
    auto room808 = Scene::create("808호(학부알바생방)", "Images/호텔 방.jpg");

    auto Gameover = Scene::create("", "Images/gameover.png");
    auto Gameover_0 = Scene::create("", "Images/gameover.png");


    //메인
    auto gamemain = Scene::create("메인화면", "Images/크라임씬.png");
    auto startbutton = Object::create("Images/GAME START.png", gamemain, 470, 30);
    startbutton->setScale(0.8f);
    startbutton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial1->enter();
        return true;
        });


    //튜토리얼1
    auto skip = Object::create("Images/스킵.png", tutorial1, 1050, 620);
    skip->setScale(0.7f);
    skip->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        caution->enter();
        return true;
        });

    //유의사항
    auto go = Object::create("Images/go.png", caution, 450, 70);
    go->setScale(0.7f);
    go->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        lobby->enter();
        setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, true);
        setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, true);
        return true;
        });

    //1->2 다음버튼
    auto nextTutorial1 = Object::create("Images/nextTutorial.png", tutorial1, 1120, 70);
    nextTutorial1->setScale(0.7f);
    nextTutorial1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial2->enter();
        return true;
        });

    //2->3 
    auto nextTutorial2 = Object::create("Images/nextTutorial.png", tutorial2, 1120, 70);
    nextTutorial2->setScale(0.7f);
    nextTutorial2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial3->enter();
        return true;
        });

    //3->4 
    auto nextTutorial3 = Object::create("Images/nextTutorial.png", tutorial3, 1120, 70);
    nextTutorial3->setScale(0.7f);
    nextTutorial3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial4->enter();
        return true;
        });


    //4->5 
    auto nextTutorial4 = Object::create("Images/nextTutorial.png", tutorial4, 1120, 70);
    nextTutorial4->setScale(0.7f);
    nextTutorial4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial5->enter();
        return true;
        });

    //이전버튼

    //2->1
    auto beforeTutorial1 = Object::create("Images/beforeTutorial.png", tutorial2, 90, 70);
    beforeTutorial1->setScale(0.7f);
    beforeTutorial1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial1->enter();
        return true;
        });

    //3->2
    auto beforeTutorial2 = Object::create("Images/beforeTutorial.png", tutorial3, 90, 70);
    beforeTutorial2->setScale(0.7f);
    beforeTutorial2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial2->enter();
        return true;
        });


    //4->3 
    auto beforeTutorial3 = Object::create("Images/beforeTutorial.png", tutorial4, 90, 70);
    beforeTutorial3->setScale(0.7f);
    beforeTutorial3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial3->enter();
        return true;
        });

    //악수선택
    auto hand = Object::create("Images/튜토리얼/악수함.png", tutorial5, 300, 65);
    hand->setScale(0.7f);
    hand->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial6_2->enter();
        return true;
        });

    auto nohand = Object::create("Images/튜토리얼/악수안함.png", tutorial5, 700, 65);
    nohand->setScale(0.7f);
    nohand->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial6_1->enter();
        return true;
        });

    //6_2->7
    auto nextTutorial5 = Object::create("Images/nextTutorial.png", tutorial6_2, 1120, 70);
    nextTutorial5->setScale(0.7f);
    nextTutorial5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial7->enter();
        return true;
        });

    //6_1->7
    auto nextTutorial6 = Object::create("Images/nextTutorial.png", tutorial6_1, 1120, 70);
    nextTutorial6->setScale(0.7f);
    nextTutorial6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial7->enter();
        return true;
        });

    //리액션
    auto reaction = Object::create("Images/튜토리얼/리액션.png", tutorial7, 500, 65);
    reaction->setScale(0.7f);
    reaction->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial8->enter();
        return true;
        });

    //게임진행선택
    auto yes = Object::create("Images/튜토리얼/긍정.png", tutorial8, 300, 65);
    yes->setScale(0.7f);
    yes->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial10->enter();
        return true;
        });

    auto no = Object::create("Images/튜토리얼/부정.png", tutorial8, 700, 65);
    no->setScale(0.7f);
    no->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        tutorial9->enter();
        return true;
        });

    //리액션
    auto reaction2 = Object::create("Images/튜토리얼/리액션2.png", tutorial10, 500, 65);
    reaction2->setScale(0.7f);
    reaction2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        caution->enter();
        return true;
        });

    auto reaction3 = Object::create("Images/튜토리얼/리액션2.png", tutorial9, 500, 65);
    reaction3->setScale(0.7f);
    reaction3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        Gameover_0->enter();
        auto Gameover_object_0 = Object::create("Images/gameover.png", Gameover_0, 0, 0);
        Gameover_object_0->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            if (x > 0 && x < 1280 && y > 0 && y < 720) {
                endGame();
            }
            return true;
            });
        return true;
        });

    auto Gameover_object = Object::create("Images/gameover.png", Gameover, 0, 0, false);
    Gameover_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 0 && x < 1280 && y > 0 && y < 720) {
            endGame();
        }
        return true;
        });
    auto bak = Object::create("Images/박사.png", Gameover, 0, 0, false);
    bak->setScale(1.2f);
    auto suk = Object::create("Images/석사.png", Gameover, 0, 0, false);
    suk->setScale(1.2f);
    auto al = Object::create("Images/학부알바생.png", Gameover, 0, 0, false);
    al->setScale(1.2f);
    auto yoen = Object::create("Images/학부연구생.png", Gameover, 0, 0, false);
    yoen->setScale(1.2f);


    int who = -1; //박사1석사2알바3연구4

    auto end_next = Object::create("Images/next.png", Gameover, 1200, 230);

    int next_num1 = 0;
    int  next_num2 = 0;
    int  next_num3 = 0;
    int  next_num4 = 0;
    end_next->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        next_num1++;
        next_num2++;
        next_num3++;
        next_num4++;

        switch (who) {

        case 1:

            bak->show();
            switch (next_num1) {

            case 1:
                showMessage("박사: 아니 증거도 제대로 없으면서 사람은 몰아세우십니까?!");
                break;
            case 2:
                showMessage("박사: 당신같은 사람은 논문 더 써봐야 정신차리지");
                break;
            case 3:
                showMessage("아쉽지만 박사에 대한 증거가 부족합니다.");
                break;
            case 4:
                bak->hide();
                end_next->hide();
                Gameover_object->show();
                break;
            }
            break;


        case 2:

            suk->show();

            switch (next_num2) {

            case 1:
                showMessage("석사: 와나~ㅋㅋㅋㅋㅋㅋ");
                break;
            case 2:
                showMessage("석사: 너 잠깐 밖으로 나와봐");
                break;
            case 3:
                showMessage("석사: 이게 어디서 함부로 조동아리를 놀려??");
                break;
            case 4:
                showMessage("아쉽지만 석사에 대한 증거가 부족합니다.");

                break;
            case 5:
                suk->hide();
                end_next->hide();
                Gameover_object->show();
                break;
            }
            break;


        case 3:

            al->show();
            switch (next_num3) {
            case 1:
                showMessage("학부알바생: 참나 증거는요?");
                break;
            case 2:
                showMessage("아쉽지만 학부알바생에 대한 증거가 부족합니다.");
                break;
            case 3:
                al->hide();
                end_next->hide();
                Gameover_object->show();
                break;
            }
            break;


        case 4:

            yoen->show();
            switch (next_num4) {
            case 1:
                showMessage("학부연구생: 하,, 저 진짜 아니라구요");
                break;
            case 2:
                showMessage("학부연구생: 잡일만 하는 것도 서러운데,,(폭풍오열 ㅠ)");
                break;
            case 3:
                showMessage("아쉽지만 학부알바생에 대한 증거가 부족합니다.");
                break;
            case 4:
                yoen->hide();
                end_next->hide();
                Gameover_object->show();
                break;
            }
            break;
        }

        return true;
        });


    Gameover_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        if (x > 0 && x < 1280 && y > 0 && y < 720) {
            endGame();
        }
        return true;
        });


    auto success = Scene::create("", "Images/성공화면.jpg");
    auto success_object = Object::create("Images/성공화면.jpg", success, 0, 0, false);
    success_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 0 && x < 1280 && y > 0 && y < 720) {
            endGame();
        }
        return true;
        });
    auto al_1 = Object::create("Images/학부알바생.png", success, 0, 0, false);
    al_1->setScale(1.2f);


    who = 5; //

    auto end_next_1 = Object::create("Images/next.png", success, 1200, 230);

    int next_num = 0;
    end_next_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        next_num++;

        switch (who) {


        case 5:

            al_1->show();
            switch (next_num) {
            case 1:
                showMessage("하,,,,");
                break;
            case 2:
                showMessage("그래 다 봐버렸네?");
                break;
            case 3:
                showMessage("그래 내가 죽였어");
                break;
            case 4:
                showMessage("근데 이상하네? 분명 그 인간이 죽으면 모든게 후련할 줄 알았는데");
                break;
            case 5:
                showMessage("이건 무슨 기분일까?");
                break;
            case 6:
                showMessage("교수의 마지막말이 계속 내 귀에 맴도는군.....");
                break;
            case 7:
                al_1->hide();
                end_next_1->hide();
                success_object->show();
                break;
            }
            break;
        }
        return true;
        });

    success_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        if (x > 0 && x < 1280 && y > 0 && y < 720) {
            endGame();
        }
        return true;
        });


    //쪽지 씬
    auto hint1_sc = Scene::create("", "Images/박사쪽지.png");
    auto hint2_sc = Scene::create("", "Images/박사쪽지2.PNG");
    auto hint3_sc = Scene::create("", "Images/석사쪽지.PNG");
    auto hint4_sc = Scene::create("", "Images/석사쪽지2.PNG");
    auto hint5_sc = Scene::create("", "Images/학부알바생쪽지.PNG");
    auto hint6_sc = Scene::create("", "Images/학부연구생쪽지.PNG");

    //선택 씬
    auto select1 = Scene::create("", "Images/박사 지목.jpg");
    auto select2 = Scene::create("", "Images/박사 지목.jpg");
    auto select3 = Scene::create("", "Images/석사 지목.jpg");
    auto select4 = Scene::create("", "Images/석사 지목.jpg");
    auto select5 = Scene::create("", "Images/알바생 지목.jpg");
    auto select6 = Scene::create("", "Images/연구생 지목.jpg");
    //선택 씬 오브젝트화
    auto select1_object = Object::create("Images/박사 지목.jpg", select1, 0, 0);
    auto select2_object = Object::create("Images/박사 지목.jpg", select2, 0, 0);
    auto select3_object = Object::create("Images/석사 지목.jpg", select3, 0, 0);
    auto select4_object = Object::create("Images/석사 지목.jpg", select4, 0, 0);
    auto select5_object = Object::create("Images/알바생 지목.jpg", select5, 0, 0);
    auto select6_object = Object::create("Images/연구생 지목.jpg", select6, 0, 0);



    //선택하기
    select1_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 180.2 && x < 538.8 && y > 113.4 && y < 205.3) {
            who = 1;
            Gameover->enter();
        }
        else if (x > 761.8 && x < 1118.1 && y > 113.4 && y < 205.3) {
            lobby->enter();
        }
        return true;
        });

    select2_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 180.2 && x < 538.8 && y > 113.4 && y < 205.3) {
            who = 1;
            Gameover->enter();
        }
        else if (x > 761.8 && x < 1118.1 && y > 113.4 && y < 205.3) {
            lobby->enter();
        }
        return true;
        });

    select3_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 180.2 && x < 538.8 && y > 113.4 && y < 205.3) {
            who = 2;
            Gameover->enter();
        }
        else if (x > 761.8 && x < 1118.1 && y > 113.4 && y < 205.3) {
            lobby->enter();
        }
        return true;
        });

    select4_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 180.2 && x < 538.8 && y > 113.4 && y < 205.3) {
            who = 2;
            Gameover->enter();
        }
        else if (x > 761.8 && x < 1118.1 && y > 113.4 && y < 205.3) {
            lobby->enter();
        }
        return true;
        });

    //장미 엔딩씬 //solve=>1 참엔딩 //0이면=>게임오버

    int solve = 0;
    select5_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {

        //겜 오버
        if (x > 180.2 && x < 538.8 && y > 113.4 && y < 205.3 && solve == 0) {
            who = 3;
            Gameover->enter();

        }

        //겜 성공
        else if (x > 180.2 && x < 538.8 && y > 113.4 && y < 205.3 && solve == 1) {
            success->enter();
        }
        else if (x > 761.8 && x < 1118.1 && y > 113.4 && y < 205.3) {
            lobby->enter();
        }
        return true;
        });

    select6_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 180.2 && x < 538.8 && y > 113.4 && y < 205.3) {
            who = 4;
            Gameover->enter();
        }
        else if (x > 761.8 && x < 1118.1 && y > 113.4 && y < 205.3) {
            lobby->enter();
        }
        return true;
        });


    //변론씬
    auto talk1 = Scene::create("", "Images/박사변론.PNG");
    auto talk2 = Scene::create("", "Images/박사변론2.PNG");
    auto talk3 = Scene::create("", "Images/석사변론.PNG");
    auto talk4 = Scene::create("", "Images/석사변론2.PNG");
    auto talk5 = Scene::create("", "Images/학부알바생변론.PNG");
    auto talk6 = Scene::create("", "Images/학부연구생변론.PNG");


    auto lobby_object = Object::create("Images/호텔 복도.jpg", lobby, 0, 0);
    auto arrow804 = Object::create("Images/화살표.png", room804, 10, 600);
    auto arrow805 = Object::create("Images/화살표.png", room805, 10, 600);
    auto arrow806 = Object::create("Images/화살표.png", room806, 10, 600);
    auto arrow807 = Object::create("Images/화살표.png", room807, 10, 600);
    auto arrow808 = Object::create("Images/화살표.png", room808, 10, 600);

    auto death = Object::create("Images/시체.png", room804, 696, 9);
    //변론 넘어가기
    auto next1 = Object::create("Images/next.png", hint1_sc, 1150, 60);
    next1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        talk1->enter();
        return true;
        });
    auto next2 = Object::create("Images/next.png", hint2_sc, 1150, 60);
    next2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        talk2->enter();
        return true;
        });
    auto next3 = Object::create("Images/next.png", hint3_sc, 1150, 60);
    next3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        talk3->enter();
        return true;
        });
    auto next4 = Object::create("Images/next.png", hint4_sc, 1150, 60);
    next4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        talk4->enter();
        return true;
        });
    auto next5 = Object::create("Images/next.png", hint5_sc, 1150, 60);
    next5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        talk5->enter();
        return true;
        });
    auto next6 = Object::create("Images/next.png", hint6_sc, 1150, 60);
    next6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        talk6->enter();
        return true;
        });

    //결정화면 넘어가기
    auto next_1 = Object::create("Images/next.png", talk1, 1150, 60);
    next_1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        select1->enter();
        return true;
        });
    auto next_2 = Object::create("Images/next.png", talk2, 1150, 60);
    next_2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        select2->enter();
        return true;
        });
    auto next_3 = Object::create("Images/next.png", talk3, 1150, 60);
    next_3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        select3->enter();
        return true;
        });
    auto next_4 = Object::create("Images/next.png", talk4, 1150, 60);
    next_4->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        select4->enter();
        return true;
        });
    auto next_5 = Object::create("Images/next.png", talk5, 1150, 60);
    next_5->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        select5->enter();
        return true;
        });
    auto next_6 = Object::create("Images/next.png", talk6, 1150, 60);
    next_6->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        select6->enter();
        return true;
        });

    //힌트 생성
    ObjectPtr HInt_board_a[6];
    ObjectPtr HInt_board_b[6];
    ObjectPtr HInt_board_c[6];
    ObjectPtr HInt_board_d[6];
    ObjectPtr HInt_board_e[6];

    for (int i = 0; i < 6; i++) {
        string filename = "Images/" + to_string(i + 1) + ".png";
        HInt_board_a[i] = Object::create(filename, room804, 440 + i * 80, 650, false);
        HInt_board_b[i] = Object::create(filename, room805, 440 + i * 80, 650, false);
        HInt_board_c[i] = Object::create(filename, room806, 440 + i * 80, 650, false);
        HInt_board_d[i] = Object::create(filename, room807, 440 + i * 80, 650, false);
        HInt_board_e[i] = Object::create(filename, room808, 440 + i * 80, 650, false);
    }

    lobby_object->setOnMouseCallback([&](ObjectPtr object, double x, double y, MouseAction action)->bool {
        if (x > 71.8 && x < 271.8 && y > 192.2 && y < 817.4) {
            room804->enter();
            door_sound->play();
        }
        if (x > 305.8 && x < 505.8 && y > 192.2 && y < 817.4) {
            room805->enter();
            door_sound->play();
        }
        if (x > 539.8 && x < 739.8 && y > 192.2 && y < 817.4) {
            room806->enter();
            door_sound->play();
        }
        if (x > 773.8 && x < 973.8 && y > 192.2 && y < 817.4) {
            room807->enter();
            door_sound->play();
        }
        if (x > 1007.8 && x < 1207.8 && y > 192.2 && y < 817.4) {
            room808->enter();
            door_sound->play();
        }
        return true;
        });

    arrow804->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        lobby->enter();
        return true;
        });
    arrow805->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        lobby->enter();
        return true;
        });
    arrow806->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        lobby->enter();
        return true;
        });
    arrow807->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        lobby->enter();
        return true;
        });
    arrow808->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        lobby->enter();
        return true;
        });

    //804호(교수방)
    auto spray = Object::create("Images/천식스프레이.png", room804, 540, 345);
    spray->setScale(0.1f);
    spray->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        spray->pick();
        return true;
        });

    auto jumping_rope = Object::create("Images/줄넘기줄.png", room804, 200, 75);
    jumping_rope->setScale(0.2f);
    jumping_rope->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        jumping_rope->pick();
        return true;
        });

    //805호(박사방)
    auto monitor = Scene::create("805호", "Images/박사 노트북화면.jpg");
    auto background = Object::create("Images/바탕화면.png", monitor, 33, 21);
    background->setScale(0.63f);

    auto backto805 = Object::create("Images/화살표.png", monitor, 10, 600);
    backto805->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        room805->enter();
        return true;
        });

    auto notebook = Object::create("Images/노트북.png", room805, 1070, 260);
    notebook->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        monitor->enter();
        return true;
        });


    //노트북 모니터 화면
    auto chrome = Object::create("Images/크롬.png", monitor, 100, 560);
    chrome->setScale(0.25f);

    auto folder1 = Object::create("Images/직박구리폴더.png", monitor, 100, 410);
    folder1->setScale(0.25f);

    auto folder2 = Object::create("Images/졸논폴더.png", monitor, 100, 260);
    folder2->setScale(0.25f);

    auto folder3 = Object::create("Images/과제폴더.png", monitor, 100, 100);
    folder3->setScale(0.25f);

    int com_num = 0;

    auto email = Object::create("Images/크롬메일창.png", monitor, 300, 150, false);
    email->setScale(0.8f);

    int once_email = 0;

    email->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 820 && y > 600) {
            email->hide();
        }
        return true;
        });


    int once_papers = 0;
    auto papers = Object::create("Images/졸논폴더창.png", monitor, 200, 150, false);
    papers->setScale(0.45f);
    papers->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 820 && y > 820) {
            papers->hide();
        }
        return true;
        });

    chrome->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        email->show();
        if (once_email == 0) {
            com_num++;
        }
        once_email++;
        if (com_num == 2) {
            hint_sound->play();
            int hint2 = 1;
            HInt_board_a[hint2]->show();
            HInt_board_b[hint2]->show();
            HInt_board_c[hint2]->show();
            HInt_board_d[hint2]->show();
            HInt_board_e[hint2]->show();

            HInt_board_a[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_b[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_c[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_d[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_e[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
        }
        return true;
        });


    folder2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        papers->show();

        if (once_papers == 0) {
            com_num++;
        }

        once_papers++;

        if (com_num == 2) {
            hint_sound->play();
            int hint2 = 1;
            HInt_board_a[hint2]->show();
            HInt_board_b[hint2]->show();
            HInt_board_c[hint2]->show();
            HInt_board_d[hint2]->show();
            HInt_board_e[hint2]->show();

            HInt_board_a[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_b[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_c[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_d[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
            HInt_board_e[hint2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
                hint2_sc->enter();
                return true;
                });
        }
        return true;
        });


    auto jumping_rope_handle = Object::create("Images/줄넘기손잡이.png", room805, 840, 105);
    jumping_rope_handle->setScale(0.2f);
    jumping_rope_handle->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        jumping_rope_handle->pick();
        return true;
        });


    //806호(석사방)
    auto medicine1 = Object::create("Images/누워.png", room806, 540, 345);
    auto medicine = Object::create("Images/내복약.png", room806, 350, 120, false);
    medicine1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        medicine->show();
        medicine->setScale(0.6f);
        return true;
        });
    medicine->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        medicine->pick();
        medicine1->hide();
        return true;
        });


    auto paper = Object::create("Images/구겨진 포스터.png", room806, 1270, 265);
    paper->setScale(0.3f);
    auto paperBig = Object::create("Images/포스터내용.png", room806, -100, 0, false);
    paperBig->setScale(1.1f);

    paper->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        paperBig->show();
        return true;
        });

    paperBig->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        paper->hide();
        paperBig->pick();
        return true;
        });

    auto picture1 = Object::create("Images/찢긴사진1.png", room806, 50, 15);
    medicine->setScale(0.3f);
    picture1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        picture1->pick();
        return true;
        });

    auto picture2 = Object::create("Images/찢긴사진2.png", room806, 900, 25);
    medicine->setScale(0.3f);
    picture2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        picture2->pick();
        return true;
        });


    //807호(학부연구생방)
    auto receiptSmall = Object::create("Images/영수증누움.png", room807, 500, 215);
    receiptSmall->setScale(0.3f);

    auto receiptBig = Object::create("Images/영수증.png", room807, 400, 190, false);

    receiptSmall->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        receiptBig->show();
        receiptBig->setScale(1.6f);
        return true;
        });
    receiptBig->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        receiptBig->pick();
        receiptSmall->hide();
        return true;
        });

    auto carrierClose = Object::create("Images/캐리어닫.png", room807, 600, 70);
    carrierClose->setScale(0.4f);

    auto carrierOpen = Object::create("Images/캐리어열.png", room807, 600, 70, false);
    carrierOpen->setScale(0.4f);

    auto letter = Object::create("Images/편지봉투.png", room807, 720, 225, false);
    letter->setScale(0.6f);

    auto letterIn = Object::create("Images/편지내용.png", room807, 170, 80, false);

    letter->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        letterIn->show();
        letterIn->setScale(1.1f);
        return true;
        });
    letterIn->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        letterIn->pick();
        letter->hide();
        return true;
        });

    carrierClose->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        carrierOpen->show();
        carrierClose->hide();
        letter->show();
        return true;
        });



    //808호(학부알바생방)
    auto paper_dummy = Object::create("Images/종이뭉치.png", room808, 5, 270);
    auto paper1 = Object::create("Images/진단서.png", room808, 450, 140, false);
    paper_dummy->setScale(0.1f);
    paper_dummy->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        paper1->show();
        return true;
        });
    paper1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        paper_dummy->pick();
        paper1->hide();
        return true;
        });

    auto drug = Object::create("Images/약통같은껌통.png", room808, 1050, 265);
    drug->setScale(1.3f);
    auto drug_Big = Object::create("Images/약통같은껌통큰거.png", room808, 600, 80, false);
    drug->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        drug_Big->show();
        drug_Big->setScale(1.1f);
        return true;
        });
    drug_Big->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        drug_Big->pick();
        drug->hide();
        return true;
        });

    auto phone = Object::create("Images/누운스마트폰.png", room808, 570, 343);
    phone->setScale(0.08f);

    auto phoneBig = Object::create("Images/스마트폰 화면 꺼짐.png", room808, 450, 80, false);
    phoneBig->setScale(1.0f);

    auto phoneText = Object::create("Images/스마트폰문자.png", room808, 450, 80, false);
    phoneText->setScale(1.0f);

    phone->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        phoneBig->show();
        return true;
        });

    phoneBig->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        phoneText->show();
        phoneBig->hide();
        return true;
        });

    phoneText->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        phoneText->pick();
        phone->hide();
        return true;
        });


    auto HInt1 = Object::create("Images/줄넘기.png");
    HInt1->defineCombination(jumping_rope_handle, jumping_rope);
    HInt1->setOnCombineCallback([&](ObjectPtr)->bool {
        hint_sound->play();
        int hint1 = 0;
        HInt_board_a[hint1]->show();
        HInt_board_b[hint1]->show();
        HInt_board_c[hint1]->show();
        HInt_board_d[hint1]->show();
        HInt_board_e[hint1]->show();
        HInt_board_a[hint1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint1_sc->enter();
            return true;
            });
        HInt_board_b[hint1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint1_sc->enter();
            return true;
            });
        HInt_board_c[hint1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint1_sc->enter();
            return true;
            });
        HInt_board_d[hint1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint1_sc->enter();
            return true;
            });
        HInt_board_e[hint1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint1_sc->enter();
            return true;
            });

        return true;
        });

    auto prof_picture = Object::create("Images/교수사진.png");
    prof_picture->defineCombination(picture1, picture2);
    auto Hint3 = Object::create("Images/힌트3.png");
    Hint3->defineCombination(prof_picture, paperBig);
    Hint3->setOnCombineCallback([&](ObjectPtr)->bool {
        hint_sound->play();
        int hint3 = 2;
        HInt_board_a[hint3]->show();
        HInt_board_b[hint3]->show();
        HInt_board_c[hint3]->show();
        HInt_board_d[hint3]->show();
        HInt_board_e[hint3]->show();

        HInt_board_a[hint3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint3_sc->enter();
            return true;
            });
        HInt_board_b[hint3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint3_sc->enter();
            return true;
            });
        HInt_board_c[hint3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint3_sc->enter();
            return true;
            });
        HInt_board_d[hint3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint3_sc->enter();
            return true;
            });
        HInt_board_e[hint3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint3_sc->enter();
            return true;
            });
        return true;
        });

    auto Hint4 = Object::create("Images/힌트4.png");
    Hint4->defineCombination(medicine, spray);
    Hint4->setOnCombineCallback([&](ObjectPtr)->bool {
        hint_sound->play();
        int hint4 = 3;
        HInt_board_a[hint4]->show();
        HInt_board_b[hint4]->show();
        HInt_board_c[hint4]->show();
        HInt_board_d[hint4]->show();
        HInt_board_e[hint4]->show();

        HInt_board_a[hint4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint4_sc->enter();
            return true;
            });
        HInt_board_b[hint4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint4_sc->enter();
            return true;
            });
        HInt_board_c[hint4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint4_sc->enter();
            return true;
            });
        HInt_board_d[hint4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint4_sc->enter();
            return true;
            });
        HInt_board_e[hint4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint4_sc->enter();
            return true;
            });
        return true;
        });

    auto Hint5 = Object::create("Images/힌트5.png");
    Hint5->defineCombination(paper_dummy, drug_Big);
    Hint5->setOnCombineCallback([&](ObjectPtr)->bool {
        hint_sound->play();
        int Hint5 = 4;
        HInt_board_a[Hint5]->show();
        HInt_board_b[Hint5]->show();
        HInt_board_c[Hint5]->show();
        HInt_board_d[Hint5]->show();
        HInt_board_e[Hint5]->show();
        HInt_board_a[Hint5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint5_sc->enter();
            return true;
            });
        HInt_board_b[Hint5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint5_sc->enter();
            return true;
            });
        HInt_board_c[Hint5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint5_sc->enter();
            return true;
            });
        HInt_board_d[Hint5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint5_sc->enter();
            return true;
            });
        HInt_board_e[Hint5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint5_sc->enter();
            return true;
            });
        return true;
        });

    auto Hint6 = Object::create("Images/힌트6.png");
    Hint6->defineCombination(letterIn, receiptBig);
    Hint6->setOnCombineCallback([&](ObjectPtr)->bool {
        hint_sound->play();
        int Hint6 = 5;
        HInt_board_a[Hint6]->show();
        HInt_board_b[Hint6]->show();
        HInt_board_c[Hint6]->show();
        HInt_board_d[Hint6]->show();
        HInt_board_e[Hint6]->show();
        HInt_board_a[Hint6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint6_sc->enter();
            return true;
            });
        HInt_board_b[Hint6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint6_sc->enter();
            return true;
            });
        HInt_board_c[Hint6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint6_sc->enter();
            return true;
            });
        HInt_board_d[Hint6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint6_sc->enter();
            return true;
            });
        HInt_board_e[Hint6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
            hint6_sc->enter();
            return true;
            });

        return true;
        });

    //금고
    auto lock_in804 = Scene::create("금고 내부", "Images/금고 안.jpg");
    auto arrow_lock804 = Object::create("Images/화살표.png", lock_in804, 10, 600);
    auto lock804 = Object::create("Images/금고.png", room804, 31.9, 272.1);
    lock804->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        showKeypad("2020", lock804);
        return true;
        });
    lock804->setOnKeypadCallback([&](ObjectPtr object)->bool {
        lock_in804->enter();
        return true;
        });
    arrow_lock804->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        room804->enter();
        return true;
        });

    auto lock_in805 = Scene::create("금고 내부", "Images/금고 안.jpg");
    auto arrow_lock805 = Object::create("Images/화살표.png", lock_in805, 10, 600);
    auto lock805 = Object::create("Images/금고.png", room805, 31.9, 272.1);
    lock805->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        showKeypad("2020", lock805);
        return true;
        });
    lock805->setOnKeypadCallback([&](ObjectPtr object)->bool {
        lock_in805->enter();
        return true;
        });
    arrow_lock805->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        room805->enter();
        return true;
        });

    auto lock_in806 = Scene::create("금고 내부", "Images/금고 안.jpg");
    auto arrow_lock806 = Object::create("Images/화살표.png", lock_in806, 10, 600);
    auto lock806 = Object::create("Images/금고.png", room806, 31.9, 272.1);
    lock806->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        showKeypad("2020", lock806);
        return true;
        });
    lock806->setOnKeypadCallback([&](ObjectPtr object)->bool {
        lock_in806->enter();
        return true;
        });
    arrow_lock806->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        room806->enter();
        return true;
        });

    auto lock_in807 = Scene::create("금고 내부", "Images/금고 안.jpg");
    auto arrow_lock807 = Object::create("Images/화살표.png", lock_in807, 10, 600);
    auto lock807 = Object::create("Images/금고.png", room807, 31.9, 272.1);
    lock807->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        showKeypad("2020", lock807);
        return true;
        });
    lock807->setOnKeypadCallback([&](ObjectPtr object)->bool {
        lock_in807->enter();
        return true;
        });
    arrow_lock807->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        room807->enter();
        return true;
        });

    auto lock_in808 = Scene::create("금고 내부", "Images/금고 안.jpg");
    auto diary = Object::create("Images/일기장겉.png", lock_in808, 60, 40);
    auto arrow_lock808 = Object::create("Images/화살표.png", lock_in808, 10, 600);
    auto lock808 = Object::create("Images/금고.png", room808, 31.9, 272.1);
    lock808->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        showKeypad("0414", lock808);
        return true;
        });
    lock808->setOnKeypadCallback([&](ObjectPtr object)->bool {
        lock_in808->enter();
        return true;
        });
    arrow_lock808->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        room808->enter();
        return true;
        });

    //일기장 내용
    auto page1 = Scene::create("", "Images/슬라이드1.PNG");
    auto page2 = Scene::create("", "Images/슬라이드2.PNG");
    auto page3 = Scene::create("", "Images/슬라이드3.PNG");
    auto page4 = Scene::create("", "Images/슬라이드4.PNG");
    auto page5 = Scene::create("", "Images/슬라이드5.PNG");
    auto page6 = Scene::create("", "Images/슬라이드6.PNG");
    auto page7 = Scene::create("", "Images/슬라이드7.PNG");
    auto page8 = Scene::create("", "Images/슬라이드8.PNG");
    auto page9 = Scene::create("", "Images/슬라이드9.PNG");
    auto page10 = Scene::create("", "Images/슬라이드10.PNG");
    auto page11 = Scene::create("", "Images/슬라이드11.PNG");
    auto page12 = Scene::create("", "Images/슬라이드12.PNG");
    auto page13 = Scene::create("", "Images/슬라이드13.PNG");

    diary->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        page1->enter();
        return true;
        });
    auto page1_object = Object::create("Images/슬라이드1.PNG", page1, 0, 0);
    page1_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x > 600) {
            page2->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page2_object = Object::create("Images/슬라이드2.PNG", page2, 0, 0);
    page2_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page1->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page3->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page3_object = Object::create("Images/슬라이드3.PNG", page3, 0, 0);
    page3_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page2->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page4->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page4_object = Object::create("Images/슬라이드4.PNG", page4, 0, 0);
    page4_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page3->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page5->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page5_object = Object::create("Images/슬라이드5.PNG", page5, 0, 0);
    page5_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page4->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page6->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page6_object = Object::create("Images/슬라이드6.PNG", page6, 0, 0);
    page6_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page5->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page7->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page7_object = Object::create("Images/슬라이드7.PNG", page7, 0, 0);
    page7_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page6->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page8->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page8_object = Object::create("Images/슬라이드8.PNG", page8, 0, 0);
    page8_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page7->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page9->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page9_object = Object::create("Images/슬라이드9.PNG", page9, 0, 0);
    page9_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page8->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page10->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page10_object = Object::create("Images/슬라이드10.PNG", page10, 0, 0);
    page10_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page9->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page11->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page11_object = Object::create("Images/슬라이드11.PNG", page11, 0, 0);
    page11_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page10->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page12->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page12_object = Object::create("Images/슬라이드12.PNG", page12, 0, 0);
    page12_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page11->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            page13->enter();
            paper_sound->play();
        }
        return true;
        });
    auto page13_object = Object::create("Images/슬라이드13.PNG", page13, 0, 0);
    page13_object->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
        if (x < 600) {
            page12->enter();
            paper_sound->play();
        }
        else if (x > 600) {
            lobby->enter();
            back_sound1->stop();
            back_sound2->play();
            solve = 1;
        }
        return true;
        });

    startGame(gamemain);

    return 0;
}