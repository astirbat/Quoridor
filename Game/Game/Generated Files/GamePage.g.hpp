﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "GamePage.xaml.h"

void ::Game::GamePage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///GamePage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::Game::GamePage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                ::Windows::UI::Xaml::Controls::Grid^ element1 = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Grid^>(element1))->Loaded += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Game::GamePage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&GamePage::Grid_Loaded);
            }
            break;
        case 2:
            {
                this->board = safe_cast<::Windows::UI::Xaml::Controls::Grid^>(__target);
            }
            break;
        case 3:
            {
                this->player1 = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 4:
            {
                this->player1Score = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 5:
            {
                this->player2 = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 6:
            {
                this->player2Score = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 7:
            {
                ::Windows::UI::Xaml::Controls::Button^ element7 = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(element7))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Game::GamePage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&GamePage::Button_Click);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::Game::GamePage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


