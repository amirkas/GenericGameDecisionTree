//
// Created by Amir on 9/7/2024.
//

#ifndef GAME_CLASSES_H
#define GAME_CLASSES_H

#endif //GAME_CLASSES_H

#include "pch.h"
#include <vector>
#include <string>
#include <concepts>


namespace generic_cfr {

    class Game {
    public:

        class Action;
        class GameState;

        Game() : root_game_state_() {}
        virtual float Utility(const GameState& terminal_state) = 0;

    private:
        GameState root_game_state_;
    };

    class Game::Action {
    public:
        virtual std::string Hash() = 0;
    };

    class Game::GameState {

    protected:
        bool is_player_node_;
        bool is_chance_node_;
        bool is_player_one_;

    public:

        GameState() :
            is_player_node_(false), is_chance_node_(false),
            is_player_one_(false) {}

        GameState(const bool is_player_node, bool is_chance_node) :
            is_player_node_(is_player_node), is_chance_node_(is_chance_node),
            is_player_one_(false) {}

        GameState
        (
            const bool is_player_node, const bool is_chance_node,
            const bool is_player_one) :
            is_player_node_(is_player_node), is_chance_node_(is_chance_node),
            is_player_one_(is_player_one) {}

        bool IsPlayerNode() const { return is_player_node_; }
        bool IsChanceNode() const { return is_chance_node_; }
        bool IsTerminalNode() const { return !is_player_node_ && !is_chance_node_; }

        virtual std::vector<Action> PlayerActions() const = 0;
        virtual std::vector<std::pair<Action, float>> ChanceActions() const = 0;
        virtual GameState ChildGameState(const Action& a) const = 0;

        virtual std::string GameStateHash() const = 0;
        virtual std::string PlayerViewHash(bool is_player_one) const = 0;

        virtual bool operator==(const GameState &ref) const = 0;

    };



}