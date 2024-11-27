#pragma once
#include <iostream>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

namespace Utils {

#if defined(_WIN32) || defined(_WIN64)

    // Helper to manage Windows console colors
    namespace {
        inline WORD current_attributes() {
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            return csbi.wAttributes;
        }
    }

    inline std::ostream& apply_color(std::ostream& os, WORD attributes, bool is_foreground = true) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        WORD current = current_attributes();

        WORD updated_attributes;
        if (is_foreground) {
            // Preserve the background (high 4 bits) while updating the foreground (low 4 bits)
            updated_attributes = (current & 0xF0) | (attributes & 0x0F);
        } else {
            // Preserve the foreground (low 4 bits) while updating the background (high 4 bits)
            updated_attributes = (current & 0x0F) | (attributes & 0xF0);
        }

        SetConsoleTextAttribute(hConsole, updated_attributes);
        return os;
    }

    namespace Font {
        inline std::ostream& Reset(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        inline std::ostream& Black(std::ostream& os) {
            return apply_color(os, 0);
        }
        inline std::ostream& Red(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED);
        }
        inline std::ostream& Green(std::ostream& os) {
            return apply_color(os, FOREGROUND_GREEN);
        }
        inline std::ostream& Yellow(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_GREEN);
        }
        inline std::ostream& Blue(std::ostream& os) {
            return apply_color(os, FOREGROUND_BLUE);
        }
        inline std::ostream& Magenta(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_BLUE);
        }
        inline std::ostream& Cyan(std::ostream& os) {
            return apply_color(os, FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        inline std::ostream& White(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

        // Bright Colors
        inline std::ostream& BrightRed(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_INTENSITY);
        }
        inline std::ostream& BrightGreen(std::ostream& os) {
            return apply_color(os, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        inline std::ostream& BrightYellow(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        }
        inline std::ostream& BrightBlue(std::ostream& os) {
            return apply_color(os, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        inline std::ostream& BrightMagenta(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        inline std::ostream& BrightCyan(std::ostream& os) {
            return apply_color(os, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
        inline std::ostream& BrightWhite(std::ostream& os) {
            return apply_color(os, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        }
    }

    namespace Background {
        inline std::ostream& Black(std::ostream& os) {
            return apply_color(os, 0, false);
        }
        inline std::ostream& Red(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED, false);
        }
        inline std::ostream& Green(std::ostream& os) {
            return apply_color(os, BACKGROUND_GREEN, false);
        }
        inline std::ostream& Yellow(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED | BACKGROUND_GREEN, false);
        }
        inline std::ostream& Blue(std::ostream& os) {
            return apply_color(os, BACKGROUND_BLUE, false);
        }
        inline std::ostream& Magenta(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED | BACKGROUND_BLUE, false);
        }
        inline std::ostream& Cyan(std::ostream& os) {
            return apply_color(os, BACKGROUND_GREEN | BACKGROUND_BLUE, false);
        }
        inline std::ostream& White(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE, false);
        }

        // Bright Colors
        inline std::ostream& BrightRed(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED | BACKGROUND_INTENSITY, false);
        }
        inline std::ostream& BrightGreen(std::ostream& os) {
            return apply_color(os, BACKGROUND_GREEN | BACKGROUND_INTENSITY, false);
        }
        inline std::ostream& BrightYellow(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY, false);
        }
        inline std::ostream& BrightBlue(std::ostream& os) {
            return apply_color(os, BACKGROUND_BLUE | BACKGROUND_INTENSITY, false);
        }
        inline std::ostream& BrightMagenta(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY, false);
        }
        inline std::ostream& BrightCyan(std::ostream& os) {
            return apply_color(os, BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY, false);
        }
        inline std::ostream& BrightWhite(std::ostream& os) {
            return apply_color(os, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY, false);
        }
    }

#else // POSIX systems

    namespace Font {
        inline const std::string Reset = "\033[0m";
        inline const std::string Black = "\033[30m";
        inline const std::string Red = "\033[31m";
        inline const std::string Green = "\033[32m";
        inline const std::string Yellow = "\033[33m";
        inline const std::string Blue = "\033[34m";
        inline const std::string Magenta = "\033[35m";
        inline const std::string Cyan = "\033[36m";
        inline const std::string White = "\033[37m";

        // Bright Colors
        inline const std::string BrightBlack = "\033[90m";
        inline const std::string BrightRed = "\033[91m";
        inline const std::string BrightGreen = "\033[92m";
        inline const std::string BrightYellow = "\033[93m";
        inline const std::string BrightBlue = "\033[94m";
        inline const std::string BrightMagenta = "\033[95m";
        inline const std::string BrightCyan = "\033[96m";
        inline const std::string BrightWhite = "\033[97m";
    }

    namespace Background {
        inline const std::string Black = "\033[40m";
        inline const std::string Red = "\033[41m";
        inline const std::string Green = "\033[42m";
        inline const std::string Yellow = "\033[43m";
        inline const std::string Blue = "\033[44m";
        inline const std::string Magenta = "\033[45m";
        inline const std::string Cyan = "\033[46m";
        inline const std::string White = "\033[47m";

        // Bright Colors
        inline const std::string BrightBlack = "\033[100m";
        inline const std::string BrightRed = "\033[101m";
        inline const std::string BrightGreen = "\033[102m";
        inline const std::string BrightYellow = "\033[103m";
        inline const std::string BrightBlue = "\033[104m";
        inline const std::string BrightMagenta = "\033[105m";
        inline const std::string BrightCyan = "\033[106m";
        inline const std::string BrightWhite = "\033[107m";
    }

#endif

    inline void clear_screen() {
#if defined(_WIN32) || defined(_WIN64)
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coordScreen = {0, 0};
        DWORD charsWritten;
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

        DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

        FillConsoleOutputCharacter(hConsole, (TCHAR)' ', consoleSize, coordScreen, &charsWritten);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, coordScreen, &charsWritten);
        SetConsoleCursorPosition(hConsole, coordScreen);
#else
        std::cout << "\033[2J\033[H" << std::flush;
#endif
    }

    constexpr struct ClearScreenHelper {
        friend std::ostream& operator<<(std::ostream& os, const ClearScreenHelper&) {
            clear_screen();
            return os;
        }
    } ClearScreen;

}
