#include "Output.h"

void Output::Print(string stringToPrint)
{
    int n = stringToPrint.length();
    char * c_arr = new char[n+1];
    for (int i = 0; i < n; i++)
    {
        c_arr[i] = stringToPrint[i];
    }
    c_arr[n] = '\0';
    messageBuffer.push_front(c_arr);
    if (messageBuffer.size() > MAX_MESSAGES) messageBuffer.pop_back();
    PrintText();
}

void Output::InitCurses()
{
    initscr();
    getmaxyx(stdscr,y,x);
    txt = newwin(MAX_MESSAGES+3, MIN_MESSAGE_LENGTH+2, y - MAX_MESSAGES - 4, 2);
    getmaxyx(txt,txtY,txtX);
    clear();
    wclear(txt);
    if (has_colors()) start_color();

    noecho();
    cbreak();
    init_pair(GRASS_PAIR, COLOR_YELLOW, COLOR_GREEN);
    init_pair(WATER_PAIR, COLOR_CYAN, COLOR_BLUE);
    init_pair(MOUNTAIN_PAIR, COLOR_BLACK, COLOR_WHITE);
    init_pair(PLAYER_PAIR, COLOR_RED, COLOR_MAGENTA);
    init_pair(BORDER_PAIR, COLOR_YELLOW, COLOR_BLACK);
    init_pair(TXTBOX_PAIR, COLOR_WHITE, COLOR_BLACK);
    init_pair(TEXT_PAIR, COLOR_WHITE, COLOR_BLACK);
    init_pair(INPUT_PAIR, COLOR_YELLOW, COLOR_BLACK);

    PrintBorder(y,x);
    PrintText();
}

void Output::PrintBorder(int y, int x)
{
    clear();
    attron(COLOR_PAIR(BORDER_PAIR));
    border('|','|','-','-','/','\\','\\','/');
    attroff(COLOR_PAIR(BORDER_PAIR));
    refresh();
}

void Output::PrintText()
{
    wclear(txt);
    attron(COLOR_PAIR(TXTBOX_PAIR));
    wborder(txt,'|','|','-','-','/','\\','\\','/');
    if (messageBuffer.size() != 0) 
    {
      int i = 0;

      list<char*>::iterator iter = messageBuffer.begin();
      while (iter != messageBuffer.end())
      {
        char* s = *iter;

        wmove(txt,txtY-3-i,1);

        wprintw(txt,&s[0]);
        
        i++;
        iter++;
      }

    }
    attroff(COLOR_PAIR(TEXT_PAIR));

    attron(COLOR_PAIR(INPUT_PAIR));
    wmove(txt,txtY-2,1);
    wprintw(txt,"> ");
    attroff(COLOR_PAIR(INPUT_PAIR));
    wrefresh(txt);
}

void Output::Cleanup()
{
    nocbreak();
    echo();

    endwin();
}

void Output::InputChar(char * c)
{
    if (*c == '\n')
    {
      if (inputLen > 0) 
      {        
        Print(" > " + inputCh);
        referenceToProgram.parser.Parse(inputCh);
        inputCh = "";

        inputLen = 0;
      }
      
    }
    else if (*c == '\b')
    {
      if (inputLen > 0)
      {
        inputCh.pop_back();
        inputLen--;
      }

    }
    else
    {
      inputCh.push_back(*c);
      inputLen++;
      int n = inputCh.length();
      char c_arr[n+1];
      for (int i = 0; i < n; i++)
      {
        c_arr[i] = inputCh[i];
      }
      c_arr[n] = '\0';
      attron(COLOR_PAIR(INPUT_PAIR));
      wmove(txt,txtY-2,3);
      wprintw(txt,&c_arr[0]);
      attroff(COLOR_PAIR(INPUT_PAIR));
      wrefresh(txt);
    }
}

void Output::UpdateMap()
{
  
}

