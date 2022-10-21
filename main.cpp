
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;
int dir, num = 4;
int counterResult=0;
struct Snake {
    int x, y;
} s[100];

struct Fruct{
    int x,y;
}f;

void Tick() {
    for (int i = num; i > 0; --i) {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }
    if (dir == 0) s[0].y += 1;
    if (dir == 1) s[0].x -= 1;
    if (dir == 2) s[0].x += 1;
    if (dir == 3) s[0].y -= 1;

    if((s[0].x==f.x)&& (s[0].y==f.y)){
        num++;
        counterResult++;
        f.x=rand()%N;
        f.y=rand()%M;
    }
    if(s[0].x>N) s[0].x=0;
    if(s[0].x<0) s[0].x=N;
    if(s[0].y>M) s[0].y=0;
    if(s[0].y<0) s[0].y=M;

    for(int i=1;i<num;i++){
        if(s[0].x==s[i].x && s[0].y==s[i].y){
            num=i;
            counterResult=0;
        }

    }


}

int main() {
    srand(time(0));

    RenderWindow window(VideoMode(w, h), "Snake Game!");
    Texture t1, t2,t3;
    t1.loadFromFile("C:\\Users\\PC\\CLionProjects\\snakeGame\\images\\white.png");
    t2.loadFromFile("C:\\Users\\PC\\CLionProjects\\snakeGame\\images\\red.png");
    t3.loadFromFile("C:\\Users\\PC\\CLionProjects\\snakeGame\\images\\green.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);
    Sprite sprite3(t3);

    Clock clock;
    float timer = 0, delay = 0.1;

    f.x=10;
    f.y=10;
    Font font;
    if(!font.loadFromFile("C:\\Users\\PC\\CLionProjects\\snakeGame\\fonts\\arial.ttf")){
        throw std::runtime_error("no font found");
    }
    Text score;
    score.setFont(font);
    score.setCharacterSize(24);
    score.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                window.close();
            }
        }
        window.clear();
        score.setString(std::to_string(counterResult));
        window.draw(score);
//        for (int i = 0; i < N; i++) {
//            for (int j = 0; j < M; j++) {
//                sprite1.setPosition(i * size, j * size);
//                window.draw(sprite1);
//            }
//        }
        if(Keyboard::isKeyPressed(Keyboard::Left)) dir=1;
        if(Keyboard::isKeyPressed(Keyboard::Right)) dir=2;
        if(Keyboard::isKeyPressed(Keyboard::Up)) dir=3;
        if(Keyboard::isKeyPressed(Keyboard::Down)) dir=0;

        if(Keyboard::isKeyPressed(Keyboard::P)) {
            timer=0;
        }
        else if (timer > delay) {
            timer = 0;
            Tick();
        }
        for (int i = 0; i < num; i++) {
            sprite2.setPosition(s[i].x * size, s[i].y * size);
            window.draw(sprite2);
        }
        sprite3.setPosition(f.x*size,f.y*size);
        window.draw(sprite3);
        window.display();
    }
    return 0;
}
