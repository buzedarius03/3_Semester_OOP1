//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
/// Darius Buze   12213086
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "network/Server.hpp"
#include "random/Random.hpp"

#include <fstream>
#include <iostream>

///****************************************************************************************************
/// the main function
///
/// here the arguments from the commandline are checked if they are in the correct format. If any of the 5 additional
/// parameters are incorrect the program should close with the correct exit code, which is different for every mistake.
/// Afterwards the program opens 2 files and reads the content and saves it in a vector. The vectors are then shuffled
/// and at last every player gets send a card (via a server, which checks before if every player is connected) from the
/// top of the 2 decks (vectors) for every round the game should be played. So for example if there are 3 players and 2
/// rounds every player gets 2 cards from each deck --> 4 cards
///
/// i dont know why but my net exceptions didn't work
///
///****************************************************************************************************
int main(int argc, const char **argv)
{
  try
  {
    Random::initialize(); // You should keep this here as explained in the framework description

    // 1) TODO parse all arguments with error handling (number_of_players rulesets tile_deck_file animal_deck_file
    // number_of_rounds)
    if (argc != 6)
    {
      return 1;
    }

    try
    {
      int number_of_players = std::stoi(argv[1]);
      if (number_of_players < 2 || number_of_players > 4)
      {
        return 2;
      }
    }
    catch (const std::invalid_argument &ex)
    {
      return 2;
    }

    std::string ruleplates = argv[2];
    if (std::strlen(argv[2]) == 5)
    {
      for (auto letter : ruleplates)
      {
        if (letter >= 'A' && letter <= 'E')
        {
          continue;
        }
        else
        {
          return 3;
        }
      }
    }
    else
    {
      return 3;
    }

    std::ifstream tile_deck_file;
    tile_deck_file.open(argv[3]);
    if (!tile_deck_file)
    {
      return 4;
    }

    std::ifstream animal_deck_file;
    animal_deck_file.open(argv[4]);
    if (!animal_deck_file)
    {
      return 5;
    }

    std::string rounds = argv[5];
    size_t processed_characters;

    try
    {
      int number_of_rounds = std::stoi(rounds, &processed_characters);
      if (rounds.size() != processed_characters)
      {
        return 6;
      }
      if (number_of_rounds < 1 || number_of_rounds > 20)
      {
        return 6;
      }
    }
    catch (const std::invalid_argument &ex)
    {
      return 6;
    }

    // 2) TODO read tile deck file
    int number_of_players = std::stoi(argv[1]);
    int number_of_rounds = std::stoi(argv[5]);
    std::string new_tile_line;
    std::vector<std::string> tile_entrys;
    int count_entrys = 1;
    while (getline(tile_deck_file, new_tile_line))
    {
      if ((new_tile_line[0] == 'M' || new_tile_line[0] == 'W' || new_tile_line[0] == 'F' || new_tile_line[0] == 'P' ||
           new_tile_line[0] == 'R') &&
          (new_tile_line[1] == 'M' || new_tile_line[1] == 'W' || new_tile_line[1] == 'F' || new_tile_line[1] == 'P' ||
           new_tile_line[1] == 'R'))
      {
        if (new_tile_line[2] == '-')
        {
          for (size_t i = 3; i < new_tile_line.length(); i++)
          {
            if (new_tile_line[i] == 'B' || new_tile_line[i] == 'S' || new_tile_line[i] == 'H' ||
                new_tile_line[i] == 'E' || new_tile_line[i] == 'F')
            {
              continue;
            }
            else
            {
              return 7;
            }
          }
        }
        else
        {
          return 7;
        }
      }
      else
      {
        return 7;
      }
      tile_entrys.push_back(new_tile_line);
      count_entrys++;
    }

    if (count_entrys < number_of_players * number_of_rounds + 3)
    {
      return 8;
    }

    tile_deck_file.close();

    // 3) TODO read animal deck file

    std::string new_animal_line;
    std::vector<std::string> animal_entrys;
    count_entrys = 1;
    while (getline(animal_deck_file, new_animal_line))
    {
      int animal_line_length = new_animal_line.length();
      for (int i = 0; i < animal_line_length; i++)
      {
        if (animal_line_length != 1)
        {
          return 9;
        }
        if (new_animal_line[0] == 'B' || new_animal_line[0] == 'S' || new_animal_line[0] == 'H' ||
            new_animal_line[0] == 'E' || new_animal_line[0] == 'F')
        {
          continue;
        }
        else
        {
          return 9;
        }
      }

      animal_entrys.push_back(new_animal_line);
      count_entrys++;
    }
    if (count_entrys < number_of_players * number_of_rounds + 3)
    {
      return 10;
    }

    animal_deck_file.close();

    // 4) Shuffle tile deck using the Random::Shuffle(...) function
    Random::Shuffle(tile_entrys);
    // 5) Shuffle animal deck using the Random::Shuffle(...) function
    Random::Shuffle(animal_entrys);

    // This initializes the Server
    // This code line will block until all players are connected
    // The testsystem will automatically connect with the right amount of players
    // If you want to test it yourself use the GUI or the exampleClient
    net::Server server(number_of_players);

    // 4) Send the required messages by using the server.send(...) function
    // try
    //{
    int card_counter = 0;
    while (card_counter < number_of_players * number_of_rounds)
    {
      server.send(tile_entrys.front());
      tile_entrys.erase(tile_entrys.begin());
      card_counter++;
    }
    card_counter = 0;
    while (card_counter < number_of_players * number_of_rounds)
    {
      server.send(animal_entrys.front());
      animal_entrys.erase(animal_entrys.begin());
      card_counter++;
    }
    /*}
    catch(const net::TimeoutException &e){
      return -1;
    }
    catch(const net::NetworkException &e){
      return -1;
    }*/
  }
  catch (const std::bad_alloc &e)
  {
    return -2;
  }
  catch (const std::runtime_error &e)
  {
    return -3;
  }
}
