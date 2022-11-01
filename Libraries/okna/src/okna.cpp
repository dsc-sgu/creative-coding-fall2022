#include <okna.hpp>

#include <chrono>
#include <cstdint>
#include <thread>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <raylib-ext.hpp>

#define DECORATION_HEIGHT 29

Window::Window() = default;

Window::Window(int window_w, int window_h, Vector2 pos,
               bool decorated, bool resizable) :
        width(window_w), height(window_h),
        pos(pos),
        decorated(decorated),
        resizable(resizable),
        active(true),
        fill_color({0, 0, 0, 255})
{
    if (decorated)
    {
        this->pos.y += DECORATION_HEIGHT;
        window_h -= DECORATION_HEIGHT;
    }

    glfwWindowHint(GLFW_RESIZABLE, resizable);
    glfwWindowHint(GLFW_DECORATED, decorated);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_FLOATING, GL_TRUE);

    this->handle = glfwCreateWindow(window_w, window_h, "", NULL, NULL);

    if (this->handle == NULL)
    {
        std::cout << "ERROR: can't create GLFW window\n" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(this->handle);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "ERROR: can't start GLAD\n" << std::endl;
        glfwTerminate();
    }

    glViewport(0, 0, window_w, window_h);
    fill(this->fill_color);

    set_position(this->pos);
}

void
Window::set_position(Vector2 pos)
{
    this->pos = pos;
    glfwMakeContextCurrent(this->handle);
    glfwSetWindowPos(
        this->handle,
        pos.x,
        pos.y + (decorated ? DECORATION_HEIGHT : 0)
    );
}

void
Window::move(Vector2 move)
{
    set_position(this->pos + move);
}

void
Window::fill(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    this->fill_color = {r, g, b, a};
    glfwMakeContextCurrent(this->handle);
    glClearColor(
        r / 255.0f,
        g / 255.0f,
        b / 255.0f,
        a / 255.0f
    );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(this->handle);
}

void
Window::fill(Color c)
{
    fill(c.r, c.g, c.b, c.a);
}

void
Window::close()
{
    glfwDestroyWindow(this->handle);
    this->active = false;
}

void
Window::sync_size()
{
    glfwGetWindowSize(this->handle, &this->width, &this->height);
    if (decorated) this->height += DECORATION_HEIGHT;
    fill(this->fill_color);
}

void
Window::sync_position()
{
    int win_x, win_y;
    glfwGetWindowPos(this->handle, &win_x, &win_y);
    this->set_position(Vector2 {
        float(win_x),
        float(win_y - (decorated? DECORATION_HEIGHT : 0))
    });
}

void
Window::sync()
{
    glfwPollEvents();
    if (this->resizable) sync_size();
    sync_position();
    if (glfwWindowShouldClose(this->handle))
        this->close();
}


Clock::Clock(float target_fps) :
    dt(1.0f / 60.0f),
    ns_count(get_ns()),
    target_ns(1.0f / target_fps * float(1e9)) {}

void Clock::start()
{
    ns_count = this->get_ns();
}

void Clock::tick()
{
    uint64_t dt_end = get_ns();
    uint64_t ns_delta = dt_end - ns_count;
    std::this_thread::sleep_for(
        std::chrono::nanoseconds(target_ns - ns_delta)
    );

    dt_end = get_ns();
    dt = (dt_end - ns_count) / float(1e9);
    ns_count = dt_end;
}

uint64_t Clock::get_ns()
{
    using namespace std::chrono;
    return duration_cast<nanoseconds>(
        system_clock::now().time_since_epoch()
    ).count();
}

void
okna_init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void
okna_terminate()
{
    glfwTerminate();
}

Vector2
okna_get_monitor_size()
{
    int count;
    GLFWmonitor **monitor = glfwGetMonitors(&count);
    const GLFWvidmode *video_mode = glfwGetVideoMode(monitor[0]);
    return {
        float(video_mode->width),
        float(video_mode->height),
    };
}
