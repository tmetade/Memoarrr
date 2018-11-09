//
//  CardFactory.h
//  CSI2372Project
//
//  Created by Rohan Kanjani on 2018-11-09.
//  Copyright © 2018 Tyler Metade. All rights reserved.
//

#ifndef CardFactory_h
#define CardFactory_h

class CardFactory : public DeckCardFactory {
public:
    DeckCard *createCard(){
        return new Card();
    }
}

#endif /* CardFactory_h */
