#include "Header.h"
// function to color 
void set_color(const string& code)
{
    cout << "\033[" << code << "m";
}
//clear scrren function 
void clear_screen()
{
    system("cls");
}

//...................................................................................................................//
                                      //Game Class Implementation
//constructor 
Game::Game()
{
    try
    {
        W = new Word_check();
        S = new Score_info();
        E = new Easy_levels();
        H = new Difficult_levels();
    }
    catch (const bad_alloc& e) //use built in function for exception handling
    {
        //e.what() for specific message related to allocation
        cout << "Not allocate properly " << e.what() << endl;

    }
}
//menu displaying 
void Game::display_Menu() const
{
    set_color("33");
    cout << "====================================" << endl;;
    cout << " Word Guessing Game Enjoy Playing        " << endl;
    cout << "====================================" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Instructions" << endl;
    cout << "3. Highest Scores" << endl;
    cout << "4. About Us" << endl;
    cout << "5. Exit" << endl;
    set_color("0");
}
//instructions 
void Game::display_instructions() const
{
    set_color("35");
    cout << "Instructions:" << endl;
    cout << "1.You guess words in grid" << endl;
    cout << "2. Words can be horizontal, vertical, or diagonal." << endl;
    cout << "3.Easy Mode has three levels 1,2,3, and you guess words 3,5,7" << endl;
    cout << "4.Hard Mode has three levels 1, 2, 3, and you guess words 3, 5, 7" << endl;
    cout << "5. score update when that word is in grid and file " << endl;
    set_color("0");
}
//user options 
void Game::user_options()
{
    try
    {
        while (true)
        {

            // clear_screen();
             //menu displaying 
            display_Menu();
            int choice;
            set_color("36");
            cout << "Enter choice but in  nummeric only like 1,2,3,4,.. : ";
            set_color("0");
            if (!(cin >> choice))
            {
                set_color("31");
                throw exception("Invalid input type enter only nummeric digits ");
                set_color("0");
            }
            switch (choice)
            {
            case 1:
                clear_screen();
                start_game();
                clear_screen();
                break;
            case 2:
                clear_screen();
                display_instructions();
                system("pause");
                clear_screen();
                break;
            case 3:
                clear_screen();
                S->display_scores();
                system("pause");
                clear_screen();
                break;
            case 4:
                clear_screen();
                aboutus_information();
                system("pause");
                clear_screen();
                break;
            case 5:
                clear_screen();
                exit();
                return;
            default:
                set_color("31");
                cout << "Invalid option so try again" << endl;
                set_color("0");
            }
        }
    }
    catch (const exception& e)
    {

        cout << "Exception: " << e.what() << endl;
    }
}
//game start 
void Game::start_game()
{
    int choice;
    set_color("32");
    cout << "Select Mode: 1 (Easy) or 2 (Difficult): ";
    set_color("0");
    cin >> choice;
    if (choice == 1)
    {
        clear_screen();
        easy_mode();
        system("pause");
        clear_screen();
    }
    else if (choice == 2)
    {
        clear_screen();
        difficult_mode();
        system("pause");
        clear_screen();

    }
    else
    {
        //if user enter invalid mode 
        set_color("31");
        cout << "No other mode available invalid" << endl;
        set_color("0");
    }
}
//easy mode function
void Game::easy_mode()
{
    //exception handling
    try
    {
        clear_screen();
        E->play_level(10, 3, 1);  // Level 1
        clear_screen();
        E->play_level(15, 5, 2);  // Level 2
        clear_screen();
        E->play_level(20, 7, 3);  // Level 3
    }
    catch (const exception& e)
    {
        cout << "Error in Easy Mode: " << e.what() << endl;
    }
}
//difficult mode 
void Game::difficult_mode()
{
    try
    {
        clear_screen();
        H->play_level(10, 3, 1);  //1st level 
        clear_screen();
        H->play_level(15, 5, 2);   //2nd level
        clear_screen();
        H->play_level(20, 7, 3);  //3rd level 
    }
    catch (const exception& e)
    {
        cout << "Error in Hard Mode: " << e.what() << endl;
    }
}

//about us function
void Game::aboutus_information() const
{
    set_color("36");
    cout << "1. Adan Sajid (23F-0691)" << endl;
    cout << "2. Maryam Asif (23F-6030)" << endl;
    set_color("0");
}

void Game::exit() const
{
    //exception handling
    try
    {
        set_color("35");
        cout << "Exiting game. BYE BYE" << endl;
        set_color("0");
    }
    catch (const exception& e)
    {
        cout << "Error during exit: " << e.what() << endl;
    }

}
//game destructor 
Game::~Game()
{
    delete W; //deallocate objects 
    delete S;
    delete E;
    delete H;
}
//....................................................................................................................

                              // Grid Class Implementation
//constructor 
Grid::Grid()
{
    gsize = 0;
    grid = nullptr; //pointer intialize to null 
}
//allocation of grid 
void Grid::Grid_allocate(int size)
{
    try
    {
        //allocate grid dynamically 
        gsize = size;
        grid = new char* [gsize];
        for (int i = 0; i < gsize; i++)
        {
            grid[i] = new char[gsize];
            for (int j = 0; j < gsize; j++)
            {
                grid[i][j] = '.';
            }
        }
    }
    catch (const bad_alloc& e)
    {
        cout << "Error in  allocating the  grid: " << e.what() << endl;
        // throw;
    }
}
//grid with random letters and from files 
void Grid::Grid_made(const string words[], int word_count)
{
    srand(time(0));
    for (int k = 0; k < word_count; k++)
    {
        bool placed = false;
        while (!placed)
        {
            int row = rand() % gsize;
            int col = rand() % (gsize - words[k].length() + 1); // horiaznotlly words fit 
            bool can_place = true;
            //check the position of word and it true then place it to the grid
            for (int i = 0; i < words[k].length(); i++)
            {
                if (grid[row][col + i] != '.' && grid[row][col + i] != words[k][i])
                {
                    can_place = false;
                    break;
                }
            }
            //place the word ingrid by checking valid position
            if (can_place)
            {
                for (int i = 0; i < words[k].length(); i++)
                {
                    grid[row][col + i] = words[k][i];
                }
                placed = true;
            }
        }
    }
    // remaining grid fill with random letters uisng srand function
    for (int i = 0; i < gsize; i++)
    {
        for (int j = 0; j < gsize; j++)
        {
            if (grid[i][j] == '.')
            {
                grid[i][j] = 'A' + rand() % 26;
            }
        }
    }
}
//displaying grid 
void Grid::display_grid() const
{
    for (int i = 0; i < gsize; i++)

    {
        for (int j = 0; j < gsize; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
//check position of words 
bool Grid::validate_word_in_grid(const string& word) const
{

    // check the position horiazantolly
    try
    {
        for (int i = 0; i < gsize; i++)
        {
            for (int j = 0; j < gsize; j++)
            {
                if (grid[i][j] == word[0])
                {
                    int k = 0;
                    while (k < word.length() && j + k < gsize && grid[i][j + k] == word[k])
                    {
                        k++;
                    }
                    if (k == word.length()) return true;
                }
            }
        }
        //check position vertically
        for (int i = 0; i < gsize; i++)
        {
            for (int j = 0; j < gsize; j++)
            {
                if (grid[j][i] == word[0])
                {
                    int k = 0;
                    while (k < word.length() && j + k < gsize && grid[j + k][i] == word[k])
                    {
                        k++;
                    }
                    if (k == word.length())
                    {
                        return true;
                    }
                }
            }
        }
        // Check diagonally top left and bottom left 
        for (int i = 0; i < gsize; i++)
        {
            for (int j = 0; j < gsize; j++)
            {
                if (grid[i][j] == word[0])
                {
                    int k = 0;
                    while (k < word.length() && i + k < gsize && j + k < gsize && grid[i + k][j + k] == word[k])
                    {
                        k++;
                    }
                    if (k == word.length())
                    {
                        return true;
                    }
                }
            }
        }
        // Check diagonally top-right to bottom-left
        for (int i = 0; i < gsize; i++)
        {
            for (int j = 0; j < gsize; j++)
            {
                if (grid[i][j] == word[0])
                {
                    int k = 0;
                    while (k < word.length() && i + k < gsize && j - k >= 0 && grid[i + k][j - k] == word[k])
                    {
                        k++;
                    }
                    if (k == word.length())
                    {
                        return true;
                    }
                }
            }
        }
        //if not match then return false 
        return false;
    }
    //if postion is not valid and our program crash then due to this it return false and did not crash 
    catch (...)
    {
        cout << "An error occurred during check validity." << endl;
        return false;
    }
}
//grid deallocate 
void Grid::Grid_deallocate()
{
    //exception handling for bad allocation 
        try
        {
            if (grid != nullptr)
            {
                for (int i = 0; i < gsize; i++)
                {
                    delete[] grid[i];
                }
                delete[] grid;
                grid = nullptr;
            }
            else
            {
                set_color("31");
                throw std::runtime_error("Error: grid is already null during deallocation.");
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
            set_color("0");
        }
    }
//destructor 
Grid::~Grid()
{
    Grid_deallocate();
}
//................................................................................................................//

                                 // Word_check Class Implementation
//constructor 
Word_check::Word_check()
{
    dict_size = 0;
}
//load dictionary means load words from files 
void Word_check::load_dictionary(const string& filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "The words are not loaded on grid" << endl;
        return;
    }
    dict_size = 0;
    //taking input from file 
    while (file >> dictionary[dict_size])
    {
        dict_size++;
    }
    file.close();  //close file
}
//check position of that words 
bool Word_check::validate_with_dictionary(const string& word) const
{
    for (int i = 0; i < dict_size; i++)
    {
        //if that word is in dictionery then return true otherwise return false
        if (dictionary[i] == word)
            return true;
    }
    return false;
}
//check word both in file and grid 
bool Word_check::validateWord(const string& word, const string* wordList, int wordCount)
{
    string lowerWord = word;
    //if word matches with word in file then return true otherwise return false 
    for (int i = 0; i < lowerWord.length(); i++)
    {
        lowerWord[i] = tolower(lowerWord[i]);
    }
    for (int i = 0; i < wordCount; i++)
    {
        string lowerListWord = wordList[i];
        for (int j = 0; j < lowerListWord.length(); j++)
        {
            lowerListWord[j] = tolower(lowerListWord[j]);
        }
        if (lowerWord == lowerListWord)
        {
            return true;
        }
    }
    return false;
}
//destructor if use 
Word_check::~Word_check() {}
//......................................................................................................................//

                          // Score_info Class Implementation
//constructor 
Score_info::Score_info()
{
    total_score = 0;
    for (int i = 0; i < score_num; i++)
    {
        score_array[i] = 0;
    }
}
//update score 
// Implementation of Score_update
void Score_info::Score_update(int level, int words_counter)
{
    //total score update according to level and word counter that user guess
    total_score += (level * 10 + words_counter * 5);
    //score updating according to level
    score_array[level - 1] += words_counter * 5;
    cout << "Level " << level << " score updated: " << score_array[level - 1] << " points." << endl;
    cout << "Total Score: " << total_score << " points." << endl;
}

//save score 
void Score_info::Save_scores()
{
    ofstream file("scores.txt", ios::app);
    if (file)
    {
        file << "Score: " << total_score << endl;
        file.close();
    }
}
//display score
void Score_info::display_scores() const
{
    ifstream file("scores.txt");
    if (!file)
    {
        cout << "The sacores are not loading" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        cout << line << endl;  //display scores 
    }
    file.close();
}
//destructor of that class 
Score_info::~Score_info() {}
//...............................................................................................................//
                             // Level Class Implementation
//words loading 
void Level::load_words(const string& filename)
{
    ifstream file(filename);
    if (!file)
    {
        cout << "words not load from file." << endl;
        return;
    }
    counterwords = 0;
    //taking input from file
    while (file >> words[counterwords])
    {
        counterwords++;
    }
    file.close(); //cloe file
}
//destructor 
Level::~Level() {}
//......................................................................................................................//

                    // Easy_levels Class Implementation
Easy_levels::Easy_levels() {}
//esay levels 
void Easy_levels::play_level(int grid_size, int word_count, int level)
{
    // Display level
    set_color("35");
    if (level == 1)
        cout << "Level 1" << endl;
    else if (level == 2)
        cout << "Level 2" << endl;
    else if (level == 3)
        cout << "Level 3" << endl;
    set_color("0");
    G.Grid_allocate(grid_size); //grid allocation accrding to size 
    load_words("easy_words.txt"); //load words from file
    G.Grid_made(words, word_count); //grid made 
    G.display_grid();  //display grid
    Score_info S;  //score class object 
    string found_words[100]; //array of words to found and size assume 100
    int found_count = 0;
    int found_words_total = 0;
    //find word from file and check with user guess 
    for (int i = 0; i < word_count; i++)
    {
        string user_input;
        cout << "Enter a word that you found: ";
        cin >> user_input;
        //if word is already found then return false
        bool already_found = false;
        for (int j = 0; j < found_count; j++)
        {
            if (found_words[j] == user_input)
            {
                already_found = true;
                break;
            }
        }
        if (already_found)
        {
            set_color("31");
            cout << "You have already found this word." << endl;
            set_color("0");
        }
        // check position by calling function form word check class and grid validate function
        else if (Word_check::validateWord(user_input, words, word_count) && G.validate_word_in_grid(user_input))
        {
            cout << "Correct!" << endl;
            found_words[found_count++] = user_input;
            found_words_total++;
            //call score update function and uupdate according to level 1,2,3 and words that are correctly guess by user
            S.Score_update(level, 1);
        }
        else
        {
            set_color("36");
            cout << "Incorrect or not in the grid." << endl;
            set_color("0");
        }
    }
    //display total words and how much user guess
    cout << "You found " << found_words_total << " out of " << word_count << " words." << endl;
    S.Save_scores();  //save score to file
    G.Grid_deallocate();  //dealloacte grid
}

Easy_levels::~Easy_levels() {}
//..................................................................................................................//

// Difficult_levels Class Implementation
Difficult_levels::Difficult_levels() {}
//play levels for difficult mode 
void Difficult_levels::play_level(int grid_size, int word_count, int level)
{
    set_color("35");
    cout << "Difficult Level" << endl;
    set_color("0");
    G.Grid_allocate(grid_size);
    load_words("hard_words.txt");
    G.Grid_made(words, word_count);
    G.display_grid();
    string found_words[100]; // array for found words and size assume 100 
    int found_count = 0;
    int found_words_total = 0;
    Score_info S;  //object of class score
    for (int i = 0; i < word_count; i++)
    {
        string user_input;
        cout << "Enter a word you found: ";
        cin >> user_input;
        // if word is already found then return false
        bool already_found = false;
        for (int j = 0; j < found_count; j++)
        {
            if (found_words[j] == user_input)
            {
                already_found = true;
                break;
            }
        }
        if (already_found)
        {
            set_color("31");
            cout << "You have already found this word." << endl;
            set_color("0");
        }
        else if (Word_check::validateWord(user_input, words, word_count) && G.validate_word_in_grid(user_input))
        {
            cout << "Correct!" << endl;
            found_words[found_count++] = user_input; // word add to lits
            found_words_total++;
            //call score update function and uupdate according to level 1,2,3 and words that are correctly guess by user
            S.Score_update(level, 1);
        }
        else
        {
            set_color("36");
            cout << "Incorrect or not in the grid." << endl;
            set_color("0");
        }
    }
    // display total words and guessed words
    cout << "You found " << found_words_total << " out of " << word_count << " words." << endl;
    G.Grid_deallocate(); //deallcate gird 
}

Difficult_levels::~Difficult_levels() {}
//...............................................................................................................//