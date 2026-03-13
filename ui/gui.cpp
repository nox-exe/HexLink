#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <cstring>
#include "invite_system.h"
#include <ctime>

Fl_Input *codeInput;
Fl_Multiline_Output *resultBox;

void login_callback(Fl_Widget*, void*) {
    std::string code = codeInput->value();

    if (validateCode(code)) {
        auto invites = generateInviteCodes(code);
        std::string msg;

        if (code == "6E053DFE") {
            msg = "Hello, Organizer!\n\n";
        } else {
            msg = "Welcome!\nReferral Code: " + code.substr(0, 4) + "\n\n";
        }

        if (invites.empty()) {
            msg += "Limit reached: You have already\ngenerated your 2 invite codes.";
        } else {
            msg += "Your New Invite Codes:\n" + invites[0] + "\n" + invites[1];
        }
        
        resultBox->value(msg.c_str());
    } else {
        resultBox->value("INVALID CODE.\nPlease contact organizer.");
    }
    resultBox->redraw();
}

void copy_callback(Fl_Widget*, void*) {
    const char* text = resultBox->value();
    
    if (text && std::strlen(text) > 0) {
        printf("Copying to clipboard: %s\n", text);
        
        Fl::copy(text, (int)std::strlen(text), 0);
        
        Fl::copy(text, (int)std::strlen(text), 1);
        
        Fl::flush(); 
        
        fl_message("Codes copied to clipboard!");
    } else {
        fl_alert("Nothing to copy! Login first.");
    }
}
int main() {
    std::srand(std::time(0));
    Fl::scheme("gtk+");

    Fl_Window *window = new Fl_Window(400, 450, "HexLink");
    window->color(fl_rgb_color(40, 40, 40)); 

    Fl_Box *title = new Fl_Box(0, 25, 400, 40, "HexLink Invitation System");
    title->labelcolor(fl_rgb_color(100, 200, 255));
    title->labelfont(FL_HELVETICA_BOLD);
    title->labelsize(28);

    codeInput = new Fl_Input(120, 90, 160, 35);
    codeInput->color(fl_rgb_color(60, 60, 60));
    codeInput->textcolor(FL_WHITE);

    Fl_Button *loginBtn = new Fl_Button(140, 145, 120, 40, "LOGIN");
    loginBtn->color(fl_rgb_color(0, 120, 215)); 
    loginBtn->labelcolor(FL_WHITE);
    loginBtn->callback(login_callback);

    resultBox = new Fl_Multiline_Output(50, 210, 300, 130);
    resultBox->box(FL_FLAT_BOX);
    resultBox->color(fl_rgb_color(50, 50, 50));
    resultBox->textcolor(fl_rgb_color(240, 240, 240));
    resultBox->textfont(FL_COURIER); 
    resultBox->textsize(15);

    Fl_Button *copyBtn = new Fl_Button(125, 365, 150, 40, "Copy Codes");
    copyBtn->color(fl_rgb_color(80, 80, 80));
    copyBtn->labelcolor(FL_WHITE);
    copyBtn->callback(copy_callback);

    window->end();
    window->show();
    return Fl::run();
}