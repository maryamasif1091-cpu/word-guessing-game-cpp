#pragma once
#pragma once
//libraries
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
//for exception handling 
#include<stdexcept>
using namespace std;
//....................................................................................................................//

//color function
void set_color(const string& code);
//claer screen
void clear_screen();
//classes prototypes
//....................................................................................................................//

class Game;
class Grid;
class Word_check;
class Score_info;
class Levels;
class Easy_levels;
//...................................................................................................................//

// Word_check Class
class Word_check
{
private:
    static const int dictioerysize = 1000; //assume size 1000
    string dictionary[dictioerysize];
    int dict_size;
public:
    //constructor 
    Word_check();
    //function that load  words from file
    void load_dictionary(const string& filename);
    //function that check valid position of word 
    bool validate_with_dictionary(const string& word) const;
    //function that check valid position of word in grid and file
    static bool validateWord(const string& word, const string* wordList, int wordCount);
    //destructor
    ~Word_check();
};
//....................................................................................................................//

// Grid Class
class Grid
{
private:
    int gsize;
    char** grid;
public:
    //constructor
    Grid();
    //allocation of grid
    void Grid_allocate(int size);
    //grid made
    void Grid_made(const string words[], int word_count);
    //display grid
    void display_grid() const;
    //check valid position of word in grid 
    bool validate_word_in_grid(const string& word) const;
    //deallocate of grid 
    void Grid_deallocate();
    //destructor
    ~Grid();
};
//....................................................................................................................//

// Score_info Class
class Score_info
{
private:
    static const int score_num = 3; //for 3 levels
    int score_array[score_num]; //array of scores
    int total_score;
public:
    //constructor
    Score_info();
    //score updating function
    void Score_update(int level, int words_counter);
    //save scores
    void Save_scores();
    //display scores
    void display_scores() const;
    //destructcor
    ~Score_info();
};
//....................................................................................................................//

// Level Class
class Level
{
protected:
    static const int MAX_WORDS = 100; //words assume 100
    string words[MAX_WORDS];
    int counterwords;
    Grid G;
    Word_check W;
public:
    //load words
    void load_words(const string& filename);
    //pure virtual beacuse its implementaion and defintion in class easy and difficut levels clas
    virtual void play_level(int grid_size, int word_count, int level) = 0;
    //destructor make virtual so if we make pointers of class then it also destroy objects and content
    virtual ~Level();
};
//....................................................................................................................//

// Easy_levels Class
class Easy_levels : public Level
{
public:
    //constructor
    Easy_levels();
    //function overriding
    void play_level(int grid_size, int word_count, int level) override;
    //destructor
    ~Easy_levels();
};
//....................................................................................................................//

// Difficult_levels Class
class Difficult_levels : public Level
{
public:
    //constructor
    Difficult_levels();
    //function overriding
    void play_level(int grid_size, int word_count, int level) override;
    //destructor
    ~Difficult_levels();
};
//....................................................................................................................//
// Game Class
class Game
{
private:
    //objects of different class 
    Word_check* W;
    Score_info* S;
    Easy_levels* E;
    Difficult_levels* H;
public:
    //constrcutor 
    Game();
    //menu display
    void display_Menu() const;
    //display instructions 
    void display_instructions() const;
    //ask user options
    void user_options();
    //game start
    void start_game();
    //esay mode controls easy mode levels 
    void easy_mode();
    //difficult mode control difficult levels
    void difficult_mode();
    //abou us information
    void aboutus_information() const;
    //exit function
    void exit() const;
    //destructor 
    ~Game();
};#pragma once
#pragma once
//libraries
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
//for exception handling 
#include<stdexcept>
using namespace std;
//....................................................................................................................//

//color function
void set_color(const string& code);
//claer screen
void clear_screen();
//classes prototypes
//....................................................................................................................//

class Game;
class Grid;
class Word_check;
class Score_info;
class Levels;
class Easy_levels;
//...................................................................................................................//

// Word_check Class
class Word_check
{
private:
    static const int dictioerysize = 1000; //assume size 1000
    string dictionary[dictioerysize];
    int dict_size;
public:
    //constructor 
    Word_check();
    //function that load  words from file
    void load_dictionary(const string& filename);
    //function that check valid position of word 
    bool validate_with_dictionary(const string& word) const;
    //function that check valid position of word in grid and file
    static bool validateWord(const string& word, const string* wordList, int wordCount);
    //destructor
    ~Word_check();
};
//....................................................................................................................//

// Grid Class
class Grid
{
private:
    int gsize;
    char** grid;
public:
    //constructor
    Grid();
    //allocation of grid
    void Grid_allocate(int size);
    //grid made
    void Grid_made(const string words[], int word_count);
    //display grid
    void display_grid() const;
    //check valid position of word in grid 
    bool validate_word_in_grid(const string& word) const;
    //deallocate of grid 
    void Grid_deallocate();
    //destructor
    ~Grid();
};
//....................................................................................................................//

// Score_info Class
class Score_info
{
private:
    static const int score_num = 3; //for 3 levels
    int score_array[score_num]; //array of scores
    int total_score;
public:
    //constructor
    Score_info();
    //score updating function
    void Score_update(int level, int words_counter);
    //save scores
    void Save_scores();
    //display scores
    void display_scores() const;
    //destructcor
    ~Score_info();
};
//....................................................................................................................//

// Level Class
class Level
{
protected:
    static const int MAX_WORDS = 100; //words assume 100
    string words[MAX_WORDS];
    int counterwords;
    Grid G;
    Word_check W;
public:
    //load words
    void load_words(const string& filename);
    //pure virtual beacuse its implementaion and defintion in class easy and difficut levels clas
    virtual void play_level(int grid_size, int word_count, int level) = 0;
    //destructor make virtual so if we make pointers of class then it also destroy objects and content
    virtual ~Level();
};
//....................................................................................................................//

// Easy_levels Class
class Easy_levels : public Level
{
public:
    //constructor
    Easy_levels();
    //function overriding
    void play_level(int grid_size, int word_count, int level) override;
    //destructor
    ~Easy_levels();
};
//....................................................................................................................//

// Difficult_levels Class
class Difficult_levels : public Level
{
public:
    //constructor
    Difficult_levels();
    //function overriding
    void play_level(int grid_size, int word_count, int level) override;
    //destructor
    ~Difficult_levels();
};
//....................................................................................................................//
// Game Class
class Game
{
private:
    //objects of different class 
    Word_check* W;
    Score_info* S;
    Easy_levels* E;
    Difficult_levels* H;
public:
    //constrcutor 
    Game();
    //menu display
    void display_Menu() const;
    //display instructions 
    void display_instructions() const;
    //ask user options
    void user_options();
    //game start
    void start_game();
    //esay mode controls easy mode levels 
    void easy_mode();
    //difficult mode control difficult levels
    void difficult_mode();
    //abou us information
    void aboutus_information() const;
    //exit function
    void exit() const;
    //destructor 
    ~Game();
};