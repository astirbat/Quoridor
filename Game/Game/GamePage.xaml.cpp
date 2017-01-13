//
// GamePage.xaml.cpp
// Implementation of the GamePage class
//

#include "pch.h"
#include "GamePage.xaml.h"
#include "IJtag.h"
#include "GameInstance.h"

using namespace Game;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

GamePage::GamePage()
{
	InitializeComponent();
}

SolidColorBrush^ gray ;
SolidColorBrush^ white ;
SolidColorBrush^ black ;
SolidColorBrush^ blue;
SolidColorBrush^ red;
GameInstance^ gameInstance;

void Game::GamePage::Grid_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	 gray = ref new SolidColorBrush(ColorHelper::FromArgb(255, 144, 144, 144));
	 white = ref new SolidColorBrush(ColorHelper::FromArgb(255, 255, 255, 255));
	 black = ref new SolidColorBrush(ColorHelper::FromArgb(255, 0, 0, 0));
	 blue = ref new SolidColorBrush(ColorHelper::FromArgb(255, 0, 0, 255));
	 red = ref new SolidColorBrush(ColorHelper::FromArgb(255, 255, 0, 0));

	 gameInstance = ref new GameInstance(2);
	 Init();
}

void Game::GamePage::Init() {
	gameInstance->NewGame();

	player1Score->Text = "" + gameInstance->GetPlayerScore(0);
	player2Score->Text = "" + gameInstance->GetPlayerScore(1);

	for (int i = 0; i <= 18; i += 2) {
		for (int j = 0; j <= 18; j++) {

			Grid^ grid = ref new Grid();
			grid->Background = gray;

			IJtag^ tagij = ref new IJtag(i, j);

			grid->Tag = tagij;
			grid->Tapped += ref new Windows::UI::Xaml::Input::TappedEventHandler(this, &Game::GamePage::OnTapped);

			board->Children->Append(grid);
			board->SetRow(grid, i);
			board->SetColumn(grid, j);
		}
	}
	for (int i = 1; i <= 18; i += 2) {
		for (int j = 0; j <= 18; j += 2) {

			Grid^ grid = ref new Grid();
			grid->Background = gray;

			IJtag^ tagij = ref new IJtag(i, j);

			grid->Tag = tagij;
			grid->Tapped += ref new Windows::UI::Xaml::Input::TappedEventHandler(this, &Game::GamePage::OnTapped);
			board->Children->Append(grid);
			board->SetRow(grid, i);
			board->SetColumn(grid, j);
		}
	}
	for (int i = 1; i <= 18; i += 2) {
		for (int j = 1; j <= 18; j += 2) {

			Grid^ grid = ref new Grid();
			grid->Background = white;

			IJtag^ tagij = ref new IJtag(i, j);

			grid->Tag = tagij;
			grid->Tapped += ref new Windows::UI::Xaml::Input::TappedEventHandler(this, &Game::GamePage::OnTapped);
			board->Children->Append(grid);
			board->SetRow(grid, i);
			board->SetColumn(grid, j);

			int trueI = (i - 1) / 2;
			int trueJ = (j - 1) / 2;
			if (trueI == 4 && trueJ == 0) {
				player1Grid = grid;
				grid->Background = blue;
			}
			if (trueI == 4 && trueJ == 8) {
				player2Grid = grid;
				grid->Background = red;
			}
		}
	}

	player1->Foreground = blue;
	player1Score->Foreground = blue;
	player2->Foreground = red;
	player2Score->Foreground = red;

	ChangePlayer(-1);
}

void Game::GamePage::ChangePlayer(int oldPlayer) {
	if (oldPlayer == 0)
		player1->FontSize = 16;
	if (oldPlayer == 1)
		player2->FontSize = 16;
	if (gameInstance->GetCurrentPlayer() == 0)
		player1->FontSize = 20;
	if (gameInstance->GetCurrentPlayer() == 1)
		player2->FontSize = 20;
}

void Game::GamePage::MovePlayer(Grid ^grid, int oldPlayer) {
	if (oldPlayer == 0)
		player1Grid->Background = white;
	if(oldPlayer==1)
		player2Grid->Background = white;

	if (oldPlayer == 0) {
		grid->Background = blue;
		player1Grid = grid;
	}
	if (oldPlayer == 1) {
		grid->Background = red;
		player2Grid = grid;
	}
}

void Game::GamePage::ClickBorder(Grid ^grid, int i, int j) {

	int _oldPlayer = gameInstance->GetCurrentPlayer();

	if (gameInstance->AddWall(i, j)) {
		grid->Background = black;

		ChangePlayer(_oldPlayer);
	}
}

void Game::GamePage::ClickContent(Grid ^grid,int i, int j) {
	int _oldPlayer = gameInstance->GetCurrentPlayer();

	if (gameInstance->Move(i, j)) {
		MovePlayer(grid,_oldPlayer);
		ChangePlayer(_oldPlayer);
	}
}

void Game::GamePage::OnTapped(Platform::Object ^sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs ^e)
{
	Grid^ grid = (Grid^)sender;
	IJtag^ tagij = (IJtag^)(grid->Tag);
	int i = tagij->GetI();
	int j = tagij->GetJ();
	
	if (i % 2 == 1 && j % 2 == 1)
		ClickContent(grid,i, j);
	else
		ClickBorder(grid,i, j);

	if (gameInstance->Win())
		Init();
}

void Game::GamePage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Init();
}
