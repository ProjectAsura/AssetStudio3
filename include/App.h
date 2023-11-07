//-----------------------------------------------------------------------------
// File : App.h
// Desc : Editor Application.
// Copyright(c) Project Asura. All right reserved.
//-----------------------------------------------------------------------------
#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <asdxApp.h>


///////////////////////////////////////////////////////////////////////////////
// App class
///////////////////////////////////////////////////////////////////////////////
class App : public asdx::Application
{
public:
    App();
    ~App();

protected:
    bool OnInit() override;
    void OnTerm() override;
    void OnFrameMove() override;
    void OnFrameRender() override;
    void OnResize(const asdx::ResizeEventArgs& args) override;
    void OnKey(const asdx::KeyEventArgs& args) override;
    void OnTyping(uint32_t keyCode) override;
    void OnDrop(const std::vector<std::string>& dropFiles) override;
};
