
#include "Input.h"

#include <cstring>

bool InputSystem::_keys[MAX_KEYS];
bool InputSystem::_buttons[MAX_BUTTONS];
bool InputSystem::_keysPrevious[MAX_KEYS];
bool InputSystem::_buttonsPrevious[MAX_BUTTONS];
std::queue<KeyEvent>  InputSystem::_keyEvents;
std::queue<MouseEvent>     InputSystem::_mouseEvents;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    InputSystem::_keys[key] = (action != GLFW_RELEASE);

    printf("Key event\n");

    KeyEvent keyEvent;

    if (InputSystem::_keysPrevious[key] == true && InputSystem::_keys[key] == true)
    {
        keyEvent.State  = InputState::PRESS;
        keyEvent.Key    = (KeyCode)key;
    } 
    else if (InputSystem::_keysPrevious[key] == false && InputSystem::_keys[key] == true)
    {
        keyEvent.State  = InputState::DOWN;
        keyEvent.Key    = (KeyCode)key;
    }
    else if (InputSystem::_keysPrevious[key] == true && InputSystem::_keys[key] == false)
    {
        keyEvent.State  = InputState::RELEASE;
        keyEvent.Key    = (KeyCode)key;
    }
    else 
    {
        keyEvent.State  = InputState::NONE;
        keyEvent.Key    = KeyCode::UNKNOWN;
    }

    memcpy(InputSystem::_keysPrevious, InputSystem::_keys, MAX_KEYS * sizeof(bool));

    InputSystem::_keyEvents.push(keyEvent);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mode)
{
    InputSystem::_buttons[button] = (action != GLFW_RELEASE);

    MouseEvent mouseEvent;

    if (InputSystem::_buttonsPrevious[button] == true && InputSystem::_buttons[button] == true)
    {
        mouseEvent.State  = InputState::PRESS;
        mouseEvent.Button = (MouseButton)button;
    } 
    else if (InputSystem::_buttonsPrevious[button] == false && InputSystem::_buttons[button] == true)
    {
        mouseEvent.State  = InputState::DOWN;
        mouseEvent.Button = (MouseButton)button;
    }
    else if (InputSystem::_buttonsPrevious[button] == true && InputSystem::_buttons[button] == false)
    {
        mouseEvent.State  = InputState::RELEASE;
        mouseEvent.Button = (MouseButton)button;
    }
    else 
    {
        mouseEvent.State  = InputState::NONE;
        mouseEvent.Button = MouseButton::M_NONE;
    }

    memcpy(InputSystem::_buttonsPrevious, InputSystem::_buttons, MAX_BUTTONS * sizeof(bool));

    InputSystem::_mouseEvents.push(mouseEvent);
}