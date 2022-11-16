#include <raylib-ext.hpp>
#include <okna.hpp>

#include <algorithm>
#include <vector>

const int BALL_W = 60;
const int BALL_H = 60;
Vector2 ball_speed = { 450, -450 };

const int BAR_W = 200;
const int BAR_H = 60;

enum Collision {
    COLLISION_LEFT,
    COLLISION_RIGHT,
    COLLISION_TOP,
    COLLISION_BOTTOM,
    COLLISION_NONE,
};

Collision collide(const Window &a, const Window &b)
{
    if (!(a.pos.x + a.width < b.pos.x || a.pos.x > b.pos.x + b.width ||
          a.pos.y + a.height < b.pos.y || a.pos.y > b.pos.y + b.height))
    {
        float dx1 = abs(a.pos.x + a.width - b.pos.x);
        float dx2 = abs(b.pos.x + b.width - a.pos.x);
        float dx = std::min({ dx1, dx2, dx1 + dx2 - std::max(a.width, b.width) });

        float dy1 = abs(a.pos.y + a.height - b.pos.y);
        float dy2 = abs(b.pos.y + b.height - a.pos.y);
        float dy = std::min({ dy1, dy2, dy1 + dy2 - std::max(a.height, b.height) });

        if (dx > dy)
        {
            float dist_t = a.pos.y + a.height - b.pos.y;
            float dist_b = b.pos.y + b.height - a.pos.y;
            return (dist_t <= dist_b) ? COLLISION_TOP : COLLISION_BOTTOM;
        }
        else
        {
            float dist_l = a.pos.x + a.width - b.pos.x;
            float dist_r = b.pos.x + b.width - a.pos.x;
            return (dist_l <= dist_r) ? COLLISION_LEFT : COLLISION_RIGHT;
        }
    }

    return COLLISION_NONE;
}

bool reflect(Window &ball, Window &obj, Vector2 &ball_speed)
{
    switch (collide(ball, obj))
    {
    case COLLISION_LEFT:
        ball_speed.x = -abs(ball_speed.x);
        ball.set_position(Vector2{ obj.pos.x - ball.width, ball.pos.y });
        break;
    case COLLISION_RIGHT:
        ball_speed.x = abs(ball_speed.x);
        ball.set_position(Vector2{ obj.pos.x + obj.width, ball.pos.y });
        break;
    case COLLISION_TOP:
        ball_speed.y = -abs(ball_speed.y);
        ball.set_position(Vector2{ ball.pos.x, obj.pos.y - ball.height });
        break;
    case COLLISION_BOTTOM:
        ball_speed.y = abs(ball_speed.y);
        ball.set_position(Vector2{ ball.pos.x, obj.pos.y + obj.height });
        break;
    case COLLISION_NONE:
        return false;
        break;
    }
    return true;
}

int main()
{
    okna_init();

    Vector2 monitor_dim = okna_get_monitor_size();

    Window bar(BAR_W, BAR_H, Vector2{
        float((monitor_dim.x - BAR_W) / 2),
        float(monitor_dim.y - BAR_H - 100),
    }, true, true);
    bar.fill(VIOLET);
    Window ball(BALL_W, BALL_H, Vector2{
        float((monitor_dim.x - BALL_W) / 2),
        float(bar.pos.y - BALL_H),
    }, false);
    ball.fill(MAROON);

    Clock clock = Clock(60);
    clock.start();
    while (bar.active)
    {
        ball.move(ball_speed * clock.dt);
        if (ball.pos.x < 0 || ball.pos.x + ball.width >= monitor_dim.x)
            ball_speed.x *= -1;
        if (ball.pos.y < 0 || ball.pos.y + ball.height >= monitor_dim.y)
            ball_speed.y *= -1;
        reflect(ball, bar, ball_speed);

        bar.sync();
        ball.sync();
        clock.tick();
    }

    okna_terminate();
    return 0;
}

