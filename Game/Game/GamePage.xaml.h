//
// GamePage.xaml.h
// Declaration of the GamePage class
//

#pragma once

#include "GamePage.g.h"

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
	private:
		void Grid_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void OnTapped(Platform::Object ^sender, Windows::UI::Xaml::Input::TappedRoutedEventArgs ^e);
		void Init();
	};
}
