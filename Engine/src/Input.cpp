
#include "Input.h"

#include <iostream>

#include <cstring>

using namespace antisocial::input;

bool Input::_keys[MAX_KEYS];
bool Input::_buttons[MAX_MOUSE_BUTTONS];
bool Input::_keysPrevious[MAX_KEYS];
bool Input::_buttonsPrevious[MAX_MOUSE_BUTTONS];
float Input::LookSensitivity;

Input::Input()
{
    updateContext(glfwGetCurrentContext());
    LookSensitivity = 0.1f;

    memset(_keys, 0, sizeof(bool) * MAX_KEYS);
    memset(_buttons, 0, sizeof(bool) * MAX_MOUSE_BUTTONS);
}

Input::~Input()
{

}

int Input::getState(KeyCode key)
{
    return (glfwGetKey(glfwGetCurrentContext(), key));
}

int Input::getState(MouseButton button)
{
    return (glfwGetMouseButton(glfwGetCurrentContext(), button));
}

bool Input::keyDown(KeyCode key)
{
    bool keyDownThisFrame = false;

    if (_keysPrevious[key] == true)
    {
        keyDownThisFrame = false;
    }
    else if (_keysPrevious[key] == false && _keys[key] == true)
    {
        keyDownThisFrame = true;
    }
    else if (_keysPrevious[key] == false && _keys[key] == false)
    {
        keyDownThisFrame = false;
    }

    return keyDownThisFrame;
}

bool Input::keyPressed(KeyCode key)
{
    return (getState(key) == GLFW_PRESS);
}

bool Input::keyUp(KeyCode key)
{
    bool keyUpThisFrame = false;

    if (_keysPrevious[key] == false)
    {
        keyUpThisFrame = false;
    }
    else if (_keysPrevious[key] == true && _keys[key] == false)
    {
        keyUpThisFrame = true;
    }
    else if (_keysPrevious[key] == true && _keys[key] == true)
    {
        keyUpThisFrame = false;
    }

    return keyUpThisFrame;
}

bool Input::getKey(KeyCode key)
{
    return _keys[key];
}

bool Input::mouseButtonDown(MouseButton button)
{
    bool buttonDownThisFrame = false;

    if (_buttonsPrevious[button] == true)
    {
        buttonDownThisFrame = false;
    }
    else if (_buttonsPrevious[button] == false && _buttons[button] == true)
    {
        buttonDownThisFrame = true;
    }
    else if (_buttonsPrevious[button] == false && _buttons[button] == false)
    {
        buttonDownThisFrame = false;
    }

    return buttonDownThisFrame;
}

bool Input::mouseButtonPressed(MouseButton button)
{
    return (getState(button) == GLFW_PRESS);
}

bool Input::mouseButtonUp(MouseButton button)
{
    bool buttonUpThisFrame = false;

    if (_buttonsPrevious[button] == false)
    {
        buttonUpThisFrame = false;
    }
    else if (_buttonsPrevious[button] == true && _buttons[button] == false)
    {
        buttonUpThisFrame = true;
    }
    else if (_buttonsPrevious[button] == true && _buttons[button] == true)
    {
        buttonUpThisFrame = false;
    }

    return buttonUpThisFrame;
}

glm::vec2 Input::getCurrentCursorPos()
{
    double xpos, ypos;
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
    return glm::vec2((float)xpos, (float)ypos);
}

void Input::updateContext(GLFWwindow* window)
{
    if (window != NULL)
    {
        glfwSetKeyCallback(window, key_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);
        glfwSetCursorPosCallback(window, cursor_movement_callback);
        glfwSetScrollCallback(window, scroll_callback);
    }
}

void Input::UpdateStates()
{
    memcpy(_keysPrevious, _keys, MAX_KEYS * sizeof(bool));
    memcpy(_buttonsPrevious, _buttons, MAX_MOUSE_BUTTONS * sizeof(bool));
}

void antisocial::input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    Input::_keys[key] = (action != GLFW_RELEASE);
}

void antisocial::input::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    Input::_buttons[button] = (action != GLFW_RELEASE);
}

void antisocial::input::cursor_movement_callback(GLFWwindow* window, double xpos, double ypos)
{

}

void antisocial::input::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{

}
