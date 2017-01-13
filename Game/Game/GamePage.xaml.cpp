//
// GamePage.xaml.cpp
// Implementation of the GamePage class
//

#include "pch.h"
#include "GamePage.xaml.h"
#include "IJtag.h"

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


void Game::GamePage::Grid_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Color gray = ColorHelper::FromArgb(255, 144, 144, 144);

	for (int i = 0; i <= 18; i+=2) {
		for (int j = 0; j <= 18; j++) {

			Grid^ grid = ref new Grid();
			grid->Background = ref new SolidColorBrush(gray);
			
			IJtag^ tagij = ref new IJtag(i,j);

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
			grid->Background = ref new SolidColorBrush(gray);

			IJtag^ tagij = ref new IJtag(i,j);

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
			IJtag^ tagij = ref new IJtag(i,j);

			grid->Tag = tagij;
			grid->Tapped += ref new Windows::UI::Xaml::Input::TappedEventHandler(this, &Game::GamePage::OnTapped2);
			board->Children->Append(grid);
			board->SetRow(grid, i);
			board->SetColumn(grid, j);
		}
	}
}

void ClickBorder(int i, int j) {

}
void ClickContent(int i, int j) {

}

void Game::GamePage::OnTapped(Platform::Object ^sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs ^e)
{
	Grid^ grid = (Grid^)sender;
	IJtag^ tagij = (IJtag^)(grid->Tag);
	ClickBorder(tagij->GetI(), tagij->GetJ());
}
void Game::GamePage::OnTapped2(Platform::Object ^sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs ^e)
{
	Grid^ grid = (Grid^)sender;
	IJtag^ tagij = (IJtag^)(grid->Tag);
	ClickContent(tagij->GetI(), tagij->GetJ());
}
