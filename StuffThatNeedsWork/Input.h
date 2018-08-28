
#ifndef INPUT_H
#define INTPU_H

#include "vendor/ECS/ECS.h"
#include <GLFW/glfw3.h>

#include <queue>

using namespace ECS;

#define MAX_KEYS    256
#define MAX_BUTTONS 8

enum KeyCode
{
    UNKNOWN         = GLFW_KEY_UNKNOWN,
    SPACE           = GLFW_KEY_SPACE,
    APOSTROPHE      = GLFW_KEY_APOSTROPHE,
    COMMA           = GLFW_KEY_COMMA,
    PERIOD          = GLFW_KEY_PERIOD,
    MINUS           = GLFW_KEY_MINUS,
    ZERO            = GLFW_KEY_0,
    ONE             = GLFW_KEY_1,
    TWO             = GLFW_KEY_2,
    THREE           = GLFW_KEY_3,
    FOUR            = GLFW_KEY_4,
    FIVE            = GLFW_KEY_5,
    SIX             = GLFW_KEY_6,
    SEVEN           = GLFW_KEY_7,
    EIGHT           = GLFW_KEY_8,
    NINE            = GLFW_KEY_9,
    SEMICOLON       = GLFW_KEY_SEMICOLON,
    EQUAL_SIGN      = GLFW_KEY_EQUAL,
    A               = GLFW_KEY_A,
    B               = GLFW_KEY_B,
    C               = GLFW_KEY_C,
    D               = GLFW_KEY_D,
    E               = GLFW_KEY_E,
    F               = GLFW_KEY_F,
    G               = GLFW_KEY_G,
    H               = GLFW_KEY_H,
    I               = GLFW_KEY_I,
    J               = GLFW_KEY_J,
    K               = GLFW_KEY_K,
    L               = GLFW_KEY_L,
    M               = GLFW_KEY_M,
    N               = GLFW_KEY_N,
    O               = GLFW_KEY_O,
    P               = GLFW_KEY_P,
    Q               = GLFW_KEY_Q,
    R               = GLFW_KEY_R,
    S               = GLFW_KEY_S,
    T               = GLFW_KEY_T,
    U               = GLFW_KEY_U,
    V               = GLFW_KEY_V,
    W               = GLFW_KEY_W,
    X               = GLFW_KEY_Y,
    Y               = GLFW_KEY_Y,
    Z               = GLFW_KEY_Z,
    K_ESCAPE        = GLFW_KEY_ESCAPE,
    K_ENTER         = GLFW_KEY_ENTER,
    K_TAB           = GLFW_KEY_TAB,
    K_BACKSPACE     = GLFW_KEY_BACKSPACE,
    K_INSERT        = GLFW_KEY_INSERT,
    K_DELETE        = GLFW_KEY_DELETE,
    K_RIGHT         = GLFW_KEY_RIGHT,
    K_LEFT          = GLFW_KEY_LEFT,
    K_UP            = GLFW_KEY_UP,
    K_DOWN          = GLFW_KEY_DOWN,
    K_PAGE_UP       = GLFW_KEY_PAGE_UP,
    K_PAGE_DOWN     = GLFW_KEY_PAGE_DOWN,
    K_HOME          = GLFW_KEY_HOME,
    K_END           = GLFW_KEY_END,
    F1              = GLFW_KEY_F1,
    F2              = GLFW_KEY_F2,
    F3              = GLFW_KEY_F3,
    F4              = GLFW_KEY_F4,
    F5              = GLFW_KEY_F5,
    F6              = GLFW_KEY_F6,
    F7              = GLFW_KEY_F7,
    F8              = GLFW_KEY_F8,
    F9              = GLFW_KEY_F9,
    F10             = GLFW_KEY_F10,
    F11             = GLFW_KEY_F11,
    F12             = GLFW_KEY_F12,
    N_PAD_0         = GLFW_KEY_KP_0,
    N_PAD_1         = GLFW_KEY_KP_1,
    N_PAD_2         = GLFW_KEY_KP_2,
    N_PAD_3         = GLFW_KEY_KP_3,
    N_PAD_4         = GLFW_KEY_KP_4,
    N_PAD_5         = GLFW_KEY_KP_5,
    N_PAD_6         = GLFW_KEY_KP_6,
    N_PAD_7         = GLFW_KEY_KP_7,
    N_PAD_8         = GLFW_KEY_KP_8,
    N_PAD_9         = GLFW_KEY_KP_9,
    N_PAD_DECIMAL   = GLFW_KEY_KP_DECIMAL,
    N_PAD_DIVIDE    = GLFW_KEY_KP_DIVIDE,
    N_PAD_MULTIPLY  = GLFW_KEY_KP_MULTIPLY,
    N_PAD_SUBTRACT  = GLFW_KEY_KP_SUBTRACT,
    N_PAD_ADD       = GLFW_KEY_KP_ADD,
    N_PAD_ENTER     = GLFW_KEY_KP_ENTER,
    N_PAD_EQUAL     = GLFW_KEY_KP_EQUAL,
    LEFT_SHIFT      = GLFW_KEY_LEFT_SHIFT,
    RIGHT_SHIFT     = GLFW_KEY_RIGHT_SHIFT,
    LEFT_CTRL       = GLFW_KEY_LEFT_CONTROL,
    RIGHT_CTRL      = GLFW_KEY_RIGHT_CONTROL,
    LEFT_ALT        = GLFW_KEY_LEFT_ALT,
    RIGHT_ALT       = GLFW_KEY_RIGHT_ALT,
    LEFT_SUPER      = GLFW_KEY_LEFT_SUPER,
    RIGHT_SUPER     = GLFW_KEY_RIGHT_SUPER,
    MENU            = GLFW_KEY_MENU,
    LEFT_BRACKET    = GLFW_KEY_LEFT_BRACKET,        // [
    RIGHT_BRACKET   = GLFW_KEY_RIGHT_BRACKET,       // ]
    BACKSLASH       = GLFW_KEY_BACKSLASH,
    GRAVE_ACCENT    = GLFW_KEY_GRAVE_ACCENT,        // `
};

enum MouseButton
{
    M_NONE      = 0,
    M_ONE       = GLFW_MOUSE_BUTTON_1,
    M_TWO       = GLFW_MOUSE_BUTTON_2,
    M_THREE     = GLFW_MOUSE_BUTTON_3,
    M_FOUR      = GLFW_MOUSE_BUTTON_4,
    M_FIVE      = GLFW_MOUSE_BUTTON_5,
    M_SIX       = GLFW_MOUSE_BUTTON_6,
    M_SEVEN     = GLFW_MOUSE_BUTTON_7,
    M_EIGHT     = GLFW_MOUSE_BUTTON_8,
    M_LEFT      = GLFW_MOUSE_BUTTON_1,
    M_RIGHT     = GLFW_MOUSE_BUTTON_2,
    M_MIDDLE    = GLFW_MOUSE_BUTTON_3,
};

enum InputState 
{
    NONE    = 0,
    RELEASE = 1,
    DOWN    = 2,
    PRESS   = 3
};

struct KeyEvent
{
    KeyCode     Key;
    InputState  State;
};

struct MouseEvent 
{
    MouseButton Button;
    InputState  State;
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mode);

class InputSystem : public EntitySystem
{
public:
    InputSystem(GLFWwindow* window) 
        :   _context(window)
    {

    }

    virtual ~InputSystem() { }

    virtual void configure(class World* world) override 
    {
        glfwSetKeyCallback(_context, key_callback);
        glfwSetMouseButtonCallback(_context, mouse_button_callback);
    }

    virtual void unconfigure(class World* world) override 
    {
        glfwSetKeyCallback(_context, nullptr);
        glfwSetMouseButtonCallback(_context, nullptr);
    }

    virtual void tick(class World* world, float deltaTime) override 
    {
        while (_keyEvents.size() > 0)
        {
            world->emit<KeyEvent>(_keyEvents.front());
            _keyEvents.pop();
        }

        while (_mouseEvents.size() > 0)
        {
            world->emit<MouseEvent>(_mouseEvents.front());
            _mouseEvents.pop();
        }
    }

private:
    friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mode);

private:
    GLFWwindow*     _context;
    
    static std::queue<KeyEvent>     _keyEvents;
    static std::queue<MouseEvent>   _mouseEvents;

    static bool     _keys[MAX_KEYS];
    static bool     _buttons[MAX_BUTTONS];
    static bool     _keysPrevious[MAX_KEYS];
    static bool     _buttonsPrevious[MAX_BUTTONS];
};

#endif // INPUT_H