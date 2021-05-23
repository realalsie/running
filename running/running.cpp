#define _CRT_SECURE_NO_WARNINGS



#include <bangtal.h>

SceneID scene1, scene2;
ObjectID startbutton, endbutton, pitch1, mario1, rouis1, mush1, play1, Pitch, Mario, Rouis, Mush;
int pitch1X = 0, pitch1Y = 400;
int mario1X = 0, mario1Y = 285;
int rouis1X = 0, rouis1Y = 145;
int mush1X = 0, mush1Y = 50;


void mouseCallback(ObjectID object, int x, int y, MouseAction action) {



	if (object == endbutton) {
		endGame();
	}
	else if (object == startbutton) {
		hideObject(startbutton);
		hideObject(endbutton);
		showObject(play1);
		showMessage("피치는 마우스, 마리오는 down, 루이지는 right, 머쉬는 left 를 연타해주세요!");
	}
	else if (object == play1) {
		pitch1X = pitch1X + 30;
		locateObject(pitch1, scene1, pitch1X, pitch1Y);

		if (pitch1X > 1280) {
			enterScene(scene2);
			showObject(Pitch);

		}
	}
	
	
}





void keyboardCallback(KeyCode code, KeyState state)
{

	if (code == KeyCode::KEY_DOWN_ARROW) {		// DOWN
		mario1X = mario1X + 30;
		locateObject(mario1, scene1, mario1X, mario1Y);

		if (mario1X > 1280) {
			enterScene(scene2);
			showObject(Mario);
			}
		}
	
	else if (code == KeyCode::KEY_RIGHT_ARROW) {		// RIGHT
		rouis1X = rouis1X + 30;
		locateObject(rouis1, scene1, rouis1X, rouis1Y);

		if (rouis1X > 1280) {
			enterScene(scene2);
			showObject(Rouis);
		}
	}
	else if (code == KeyCode::KEY_LEFT_ARROW) {		// LEFT
		mush1X = mush1X + 30;
		locateObject(mush1, scene1, mush1X, mush1Y);

		if (mush1X > 1280) {
			enterScene(scene2);
			showObject(Mush);
			}
		}
	}
			


    int main(){
					setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
					setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
					setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

					setMouseCallback(mouseCallback);
					setKeyboardCallback(keyboardCallback);



					scene1 = createScene("scene1", "back.png");



					startbutton = createObject("startbutton.png");
					locateObject(startbutton, scene1, 590, 70);
					showObject(startbutton);

					endbutton = createObject("endbutton.png");
					locateObject(endbutton, scene1, 590, 20);
					showObject(endbutton);

					pitch1 = createObject("pitch1.png");
					locateObject(pitch1, scene1, pitch1X, pitch1Y);
					showObject(pitch1);

					mario1 = createObject("mario1.png");
					locateObject(mario1, scene1, mario1X, mario1Y);
					showObject(mario1);

					rouis1 = createObject("rouis1.png");
					locateObject(rouis1, scene1, rouis1X, rouis1Y);
					showObject(rouis1);

					mush1 = createObject("mush1.png");
					locateObject(mush1, scene1, mush1X, mush1Y);
					showObject(mush1);

					play1 = createObject("play.png");
					locateObject(play1, scene1, 0, 0);

					Pitch = createObject("realpitch1.png");
					locateObject(Pitch, scene2, 600, 300);
					
					Mario = createObject("realmario1.png");
					locateObject(Mario, scene2, 600, 300);

					Rouis = createObject("realrouis1.png");
					locateObject(Rouis, scene2, 0, 0);

					Mush = createObject("realmush1.png");
					locateObject(Mush, scene2, 600, 300);







					scene2 = createScene("scene2", "rank1.png");























					startGame(scene1);
				}
			
		