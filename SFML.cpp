
#include <SFML/Graphics.hpp> 
#include <ctime> 

using namespace sf;
#include "Settings.h" 
int main()
{
    setlocale(LC_ALL, "Russian");
    // Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ 
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FPS);
    //Ñîçäàíè èãðîâûõ îáúåêòîâ 
      // Ðàêåòêè  
    RectangleShape leftbat, rightbat;
    leftbat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGTH));
    leftbat.setPosition(BAT_OFFSET, (WINDOW_HEIGHT - BAT_HEIGTH) / 2);
    leftbat.setFillColor(LEFT_BAT_COLOR);
    rightbat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGTH));
    rightbat.setPosition(WINDOW_WIDTH - BAT_WIDTH - BAT_OFFSET, (WINDOW_HEIGHT - BAT_HEIGTH) / 2);
    rightbat.setFillColor(RIGHT_BAT_COLOR);
    // Ìÿ÷  
   // CircleShape ball(BALL_RADIUS); 
   // ball.setPosition((WINDOW_WIDTH - 2 * BALL_RADIUS) / 2, (WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2); 
   // ball.setFillColor(BALL_COLOR); 



    // Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî 
    while (window.isOpen())
    {


        // Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå 
        Event event;
        while (window.pollEvent(event))
        {
            // Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî? 
            if (event.type == Event::Closed)
                // òîãäà çàêðûâàåì åãî 
                window.close();
        }

        //Левая ракетка  
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            leftbat.move(0, -batDy);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            leftbat.move(0, batDy);
        }
        if (leftbat.getPosition().y < 0) {
            leftbat.setPosition(leftbat.getPosition().x, 0);
        }
        if (leftbat.getPosition().y + leftbat.getGlobalBounds().height > WINDOW_HEIGHT) {
            leftbat.setPosition(leftbat.getPosition().x, WINDOW_HEIGHT - leftbat.getGlobalBounds().height);
        }
        //Правая ракетка  
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            rightbat.move(0, -batDy);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            rightbat.move(0, batDy);
        }
        if (rightbat.getPosition().y < 0) {
            rightbat.setPosition(rightbat.getPosition().x, 0);
        }
        if (rightbat.getPosition().y + rightbat.getGlobalBounds().height > WINDOW_HEIGTH) {
            rightbat.setPosition(rightbat.getPosition().x, WINDOW_HEIGHT - rightbat.getGlobalBounds().height);
        }



        //Счёт 
           // int LeftPlayerScore = 0; 
           // int RightPlayerScore = 0;  

           /* Font font;
            font.loadFromFile("DS-DIGI.TTF");
            Text leftscoreText(std::to_string(LeftPlayerScore), font, 64);
            Text rightscoreText(std::to_string(RightPlayerScore), font, 64);
            leftscoreText.setPosition(200, 10);
            rightscoreText.setPosition(600, 10); */
        float ball_speedx = 0.f;
        float ball_speedy = 5.f;
        CircleShape ball(BALL_RADIUS);
        ball.setPosition(0, 0);
        ball.move(ball_speedx, ball_speedy);
        if (ball.getPosition().y > WINDOW_HEIGHT) {

      }




        CircleShape ball1(BALL_RADIUS);
        ball1.setPosition(100, 0);
        CircleShape ball2(BALL_RADIUS);
        ball2.setPosition(200, 0);
        CircleShape ball3(BALL_RADIUS);
        ball3.setPosition(300, 0);
        CircleShape ball4(BALL_RADIUS);
        ball4.setPosition(400, 0);
        // îáíîâëåíèå îáúåêòîâ èãðû. 
     /*  ball.move(ball_speedx, ball_speedy);
       if (ball.getPosition().x <= 0) {

           ball_speedx = -ball_speedx;
           RightPlayerScore += 1;
           rightscoreText.setString(std::to_string(RightPlayerScore));
        }
           if((ball.getPosition().x + 2 * BALL_RADIUS) >= WINDOW_WIDTH)
        {

        ball_speedx = -ball_speedx;
        LeftPlayerScore += 1;

Никита, [11.12.2022 19:32]
leftscoreText.setString(std::to_string(LeftPlayerScore));
        }
        if (ball.getPosition().y <= 0 || ball.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGTH)
        {
            ball_speedy = -ball_speedy;
        }*/

        // îòðèñîâêà îáúåêòîâ è îêíà. 
        window.clear();
        //window.draw(leftbat); 
       // window.draw(rightbat); 
        window.draw(ball);
        // window.draw(rightscoreText);  
        // window.draw(leftscoreText);  
        window.draw(ball1);
        window.draw(ball2);
        window.draw(ball3);
        window.draw(ball4);
        // Îòðèñîâêà îêíà  
        window.display();
    }

    return 0;
}