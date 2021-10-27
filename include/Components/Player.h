#pragma once

namespace Components {
    enum class Facing {
        Left, Right
    };

    enum class State {
        Idle,
        Walking,
        Attacking
    };

    class Player {
        public:
            Facing facing = Facing::Right;
            State state;
            bool isAttacking = (state == State::Attacking);
            bool canJump = (state == State::Idle || state == State::Walking);
            
    };
}