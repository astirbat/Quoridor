//
// GamePage.xaml.h
// Declaration of the GamePage class
//

#pragma once

#include "GamePage.g.h"
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Navigation;

namespace Game
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GamePage sealed
	{
	public:
		GamePage();
		void OnNavigatedTo(NavigationEventArgs ^ e) override;
	private:
		int _wI;
		int _wJ;
		Grid ^_w;
		int nrOfPlayers;
		Grid ^player1Grid;
		Grid ^player2Grid;
		Grid ^player3Grid;
		Grid ^player4Grid;
		void Grid_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void OnTapped(Platform::Object ^sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs ^e);
		void Init();
		void ChangePlayer(int oldPlayer);
		void MovePlayer(Grid ^grid,int oldPlayer);
		void ClickBorder(Grid ^grid, int i, int j);
		void ClickContent(Grid ^grid, int i, int j);
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button_Click_1(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
