﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Grid;
                ref class TextBlock;
            }
        }
    }
}

namespace Game
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class GamePage : public ::Windows::UI::Xaml::Controls::Page, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Controls::Grid^ board;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ player1;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ player1Score;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ player2;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ player2Score;
    };
}

