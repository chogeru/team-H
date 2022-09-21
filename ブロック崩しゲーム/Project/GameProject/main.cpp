//ゲーム係機能のインクルード
#include <GLLibrary.h>
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720



//--------------------------------------------
//グローバル変数領域
//--------------------------------------------
//ボールの画像オブジェクト
CImage ball;
CImage buloku1;
CImage buloku2;
CImage buloku3;
CImage buloku4;
CImage buloku5;
CImage buloku6;
CImage buloku7;
CImage buloku8;
CImage buloku9;
CImage buloku10;

int furagu1=1;
int furagu2 = 1;
int furagu3 = 1;
int furagu4 = 1;
int furagu5 = 1;
int furagu6 = 1;
int furagu7 = 1;
int furagu8 = 1;
int furagu9 = 1;
int furagu10 = 1;

//ボールの座標
CVector2D ball_pos(100, 100);
CVector2D buloku1_pos(100, 700);
CVector2D buloku2_pos(300, 700);
CVector2D buloku3_pos(500, 700);
CVector2D buloku4_pos(700, 700);
CVector2D buloku5_pos(800, 700);
CVector2D buloku6_pos(1000, 700);
CVector2D buloku7_pos(1280, 700);
CVector2D buloku8_pos(300, 500);
CVector2D buloku9_pos(500, 500);
CVector2D buloku10_pos(700, 500);

//ボールの移動ベクトル
CVector2D ball_vec(4, 4);
CVector2D bar_vec(4, 4);
//バーの画像オブジェクト
CImage bar;
//バーの座標

CVector2D bar_pos = { CVector2D(600,650) };
CImage Title;
CVector2D Title_pos = { CVector2D(600,650) };
//ゲームの状態（0:ポーズ,1:ゲーム中)
int game_state = 0;

void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	/*

	
	
	
	*/


























	switch (game_state) {
	case 0:
		//ポーズ中の更新処理
		if (PUSH(CInput::eButton10))
			game_state = 1;
		Title.Draw();

		break;
	case 1:
		
		//ゲーム中の更新処理
		//ボールの移動
		ball_pos += ball_vec;
		//上下の反射
		if (ball_pos.y < 0 || ball_pos.y > 720 - 32) {
			ball_vec.y *= -1;
		}
		//左右の反射
		if (ball_pos.x < 0 || ball_pos.x > 1280 - 32) {
			ball_vec.x *= -1;
		}
		//バーの下移動
		if (HOLD(CInput::eRight)) {
			bar_pos.x += 16;
		}
		
		//バーの上移動
		if (HOLD(CInput::eLeft)) {
			bar_pos.x -= 16;
		}
		
		//ボールの表示位置を設定
		ball.SetPos(ball_pos);
		//ボールの表示サイズを設定
		ball.SetSize(32, 32);
		//ボールを描画
		ball.Draw();
		
		//バーの表示位置を設定
		bar.SetPos(bar_pos);
		//バーの描画
		bar.Draw();
	
		if (furagu1 == 1) {
			buloku1.SetPos(buloku1_pos);
			buloku1.SetSize(100, 100);
			buloku1.Draw();
		}
		if (furagu2 == 1) {
			buloku2.SetPos(buloku2_pos);
			buloku2.SetSize(100, 100);
			buloku2.Draw();
		}
		if (furagu3 == 1) {
			buloku3.SetPos(buloku3_pos);
			buloku3.SetSize(100, 100);
			buloku3.Draw();
		}
		if (furagu4 == 1) {
			buloku4.SetPos(buloku4_pos);
			buloku4.SetSize(100, 100);
			buloku4.Draw();
		}
		if (furagu5 == 1) {
			buloku5.SetPos(buloku5_pos);
			buloku5.SetSize(100, 100);
			buloku5.Draw();
		}
		if (furagu6 == 1) {
			buloku6.SetPos(buloku6_pos);
			buloku6.SetSize(100, 100);
			buloku6.Draw();
		}
		if (furagu7 == 1) {
			buloku7.SetPos(buloku7_pos);
			buloku7.SetSize(100, 100);
			buloku7.Draw();
		}
		if (furagu8 == 1) {
			buloku8.SetPos(buloku8_pos);
			buloku8.SetSize(100, 100);
			buloku8.Draw();
		}
		if (furagu9 == 1) {
			buloku9.SetPos(buloku9_pos);
			buloku9.SetSize(100, 100);
			buloku9.Draw();
		}
		if (furagu10 == 1) {
			buloku10.SetPos(buloku10_pos);
			buloku10.SetSize(100, 100);
			buloku10.Draw();
		}
		if (ball_pos.y > 680) {
			//ボールの位置を中央にセット
			ball_pos = CVector2D(600, 300);
			//移動量もリセット
			ball_vec = CVector2D(-4, 4);
			//ポーズ状態へ
			game_state = 0;
		}
		//bar当たり判定
		if (bar_pos.y + 32 > ball_pos.y &&
			bar_pos.y < ball_pos.y + 32 &&
			bar_pos.x + 128 > ball_pos.x &&
			bar_pos.x < ball_pos.x + 32
			) {
			//跳ね返る
			ball_vec.y *= -1;
			//当たった時音
			SOUND("SE_Hit")->Play();
			//加速
			ball_vec *= 1.1f;
		}
			
		
			if 
				(buloku1_pos.y + 100 > ball_pos.y &&
				buloku1_pos.y < ball_pos.y + 32 &&
				buloku1_pos.x + 100 > ball_pos.x &&
				buloku1_pos.x < ball_pos.x + 32)
				furagu1 = 0;
				

			if (buloku2_pos.y + 100 > ball_pos.y &&
				buloku2_pos.y < ball_pos.y + 32 &&
				buloku2_pos.x + 100 > ball_pos.x &&
				buloku2_pos.x < ball_pos.x + 32)
				furagu2 = 0;

			if (buloku3_pos.y + 100 > ball_pos.y &&
				buloku3_pos.y < ball_pos.y + 32 &&
				buloku3_pos.x + 100 > ball_pos.x &&
				buloku3_pos.x < ball_pos.x + 32)
				furagu3 = 0;
		

			if (buloku4_pos.y + 100 > ball_pos.y &&
				buloku4_pos.y < ball_pos.y + 32 &&
				buloku4_pos.x + 100 > ball_pos.x &&
				buloku4_pos.x < ball_pos.x + 32)
				furagu4 = 0;

			if (buloku5_pos.y + 100 > ball_pos.y &&
				buloku5_pos.y < ball_pos.y + 32 &&
				buloku5_pos.x + 100 > ball_pos.x &&
				buloku5_pos.x < ball_pos.x + 32)
				furagu5 = 0;

			if (buloku6_pos.y + 100 > ball_pos.y &&
				buloku6_pos.y < ball_pos.y + 32 &&
				buloku6_pos.x + 100 > ball_pos.x &&
				buloku6_pos.x < ball_pos.x + 32)
				furagu6 = 0;

			if (buloku7_pos.y + 100 > ball_pos.y &&
				buloku7_pos.y < ball_pos.y + 32 &&
				buloku7_pos.x + 100 > ball_pos.x &&
				buloku7_pos.x < ball_pos.x + 32)
				furagu7 = 0;

			if (buloku8_pos.y + 100 > ball_pos.y &&
				buloku8_pos.y < ball_pos.y + 32 &&
				buloku8_pos.x + 100 > ball_pos.x &&
				buloku8_pos.x < ball_pos.x + 32)
				furagu8 = 0;

			if (buloku9_pos.y + 100 > ball_pos.y &&
				buloku9_pos.y < ball_pos.y + 32 &&
				buloku9_pos.x + 100 > ball_pos.x &&
				buloku9_pos.x < ball_pos.x + 32)
				furagu9 = 0;

			if (buloku10_pos.y + 100 > ball_pos.y &&
				buloku10_pos.y < ball_pos.y + 32 &&
				buloku10_pos.x + 100 > ball_pos.x &&
				buloku10_pos.x < ball_pos.x + 32)
				furagu10 = 0;








	}



}

	void Init(void)
	{

		CFPS::SetFPS(60);
		//フレーム制御初期化
		CFPS::Init();
		//ボタンの設定
		CInput::Init();
		CInput::SetButton(0, CInput::eButton1, 'Z');
		CInput::SetButton(0, CInput::eButton2, 'X');
		CInput::SetButton(0, CInput::eButton3, 'C');
		CInput::SetButton(0, CInput::eButton4, 'V');
		CInput::SetButton(0, CInput::eButton5, VK_SPACE);
		CInput::SetButton(0, CInput::eButton10, VK_RETURN);
		CInput::SetButton(0, CInput::eUp, VK_UP);
		CInput::SetButton(0, CInput::eDown, VK_DOWN);
		CInput::SetButton(0, CInput::eLeft, VK_LEFT);
		CInput::SetButton(0, CInput::eRight, VK_RIGHT);
		CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
		CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
		CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
		//	CInput::SetMouseInside(true);
		//	CInput::ShowCursor(false);
		CInput::Update();
		CInput::Update();



		SetCurrentDirectory("data");
		CSound::GetInstance();

		//-----------------------------------------------------
		//初期化の命令を書く
		//ゲーム起動時に一度だけ呼ばれる
		//-----------------------------------------------------
		//ボールの読み込み
		ball.Load("Image/ball.png");
		
		//バーの読み込み
		bar.Load("Image/R.png");
		Title.Load("Image/Title.png");
		SOUND("SE_Hit")->Load("Sound/SE/Hit.wav", 10);

		buloku1.Load("Image/buloku.png");
		buloku2.Load("Image/buloku.png");
		buloku3.Load("Image/buloku.png");
		buloku4.Load("Image/buloku.png");
		buloku5.Load("Image/buloku.png");
		buloku6.Load("Image/buloku.png");
		buloku7.Load("Image/buloku.png");
		buloku8.Load("Image/buloku.png");
		buloku9.Load("Image/buloku.png");
		buloku10.Load("Image/buloku.png");






		SOUND("BGM_Game")->Load("Sound/BGM/Game.wav");
		//BGM　ループ再生
		SOUND("BGM_Game")->Play(true);


	}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "math fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}
