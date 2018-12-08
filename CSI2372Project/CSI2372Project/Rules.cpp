//#define TEST_RULES_

#include "Rules.h"

Rules::Rules(int ruleType)
{
    isHardMode = ruleType == 3 || ruleType == 4;
}

bool Rules::isValid(const Game& game) const
{
    const Card * prevCard = game.getPreviousCard();
    const Card * currCard = game.getCurrentCard();
    
    //if first card flipped
    //OR curr card background matches prev card background
    //OR curr card face matches prev card face
    //OR is NOT BLOCKED
    if(prevCard == nullptr || prevCard->face[0] == currCard->face[0] ||
       prevCard->face[1].at(1) == currCard->face[1].at(1)){
        return true;
    }
    return false;
}

bool Rules::gameOver(const Game& game)
{
    return game.getRound() == 7;
}

bool Rules::roundOver(const Game& game)
{
    Player *currentPlayer;
    int numOfActivePlayers = 0;
    
    for(int  i = 0; i < 4; i++)
    {
        currentPlayer = &game.getPlayer((Player::Side)i);
        
        if(currentPlayer != nullptr && currentPlayer->isActive())
        {
            numOfActivePlayers++;
        }
    }
    return numOfActivePlayers == 1;
}

const Player& Rules::getNextPlayer(const Game& game)
{
    int playerSide = currentPlayerSide;
    
    const Player *currentPlayer = nullptr;
    currentPlayer = &game.getPlayer((Player::Side)playerSide);
    
    while (currentPlayer == nullptr)
    {
        playerSide++;
        playerSide = playerSide%4;
        currentPlayer = &game.getPlayer((Player::Side)playerSide);
    }
    playerSide++;
    playerSide = playerSide%4;

    currentPlayerSide = (Player::Side)playerSide;
    
    return *currentPlayer;
}

#ifdef TEST_RULES_
int main()
{
    Rules gameRules(1);
    Board *gameBoard = new Board(1);
    Game *game = new Game(gameBoard);
    CardDeck *cardDeck = &CardDeck::make_CardDeck();
    
    //CardDeck is not suffled so cards should have the same background
    Card *card1 = cardDeck->getNext();
    Card *card2 = cardDeck->getNext();
    game->setCurrentCard(card1);
    game->setCurrentCard(card2);
    bool isValid = gameRules.isValid(*game);
    
    Player player1("Player1");
    Player player2("Player2");
    player1.setSide(Player::Side::top);
    player2.setSide(Player::Side::bottom);
    game->addPlayer(player1);
    game->addPlayer(player2);
    
    game->getPlayer(Player::Side::top).setActive(false);
    bool isRoundOver = gameRules.roundOver(*game);
    
    for (int i = 0; i < 7; i++)
    {
        game->nextRound();
    }
    
    bool isGameOver = gameRules.gameOver(*game);
    
    Player nextPlayer = gameRules.getNextPlayer(*game);
    bool nextPlayerMatch = (nextPlayer.getName() == player1.getName() && nextPlayer.getSide() == player1.getSide());
    
    if(isValid && nextPlayerMatch && isRoundOver && isGameOver)
        std::cout << "Rules has passed its tests" << std::endl;
    else
        std::cerr << "Rules didnt pass its tests" << std::endl;
}
#endif
