
#include <Antisocial/OpenGL.h>
#include <Antisocial/Window.h>
#include <Antisocial/vendor/ECS/ECS.h>
#include <Antisocial/Transform.h>
#include <Antisocial/Input.h>
#include <Antisocial/Renderer.h>

#include <thread>
#include <mutex>
#include <future>
#include <iostream>

#include <stdio.h>


using namespace antisocial::input;
using namespace ECS;

struct TestComp
{
    TestComp(float x, float y) : x(x), y(y) {}
    TestComp() {}

    float x;
    float y;
};

class TestSystem : public EntitySystem
{
public:

    virtual ~TestSystem() {}

    virtual void tick(class World* world, float deltaTime) override 
    {
        world->each<TestComp>([&](Entity* entity, ComponentHandle<TestComp> comp) -> void {
            
            comp->x += deltaTime;
            comp->y += deltaTime;

        });
    }
};

class TransformSystem : public EntitySystem
{
public:

    virtual ~TransformSystem() {}

    virtual void tick(class World* world, float deltaTime) override 
    {
        world->each<Transform, TransformMatrix>([&](Entity* entity, ComponentHandle<Transform> t, ComponentHandle<TransformMatrix> tm) -> void {

            const Transform tf = t.get();
            tm->Model = TransformHelper::GetTransformationMatrix(tf);

        });
    }
};

struct PlayerComponent 
{
    PlayerComponent(float damage, float speed) : Damage(damage), Speed(speed) { }
    PlayerComponent() {}
    ~PlayerComponent() {}

    float Damage;
    float Speed;
};

struct HealthComponent 
{
    HealthComponent(float amount) : Amount(amount) { }
    HealthComponent() {}
    ~HealthComponent() {}

    float Amount;
};

class PlayerSystem  :   public EntitySystem
{
public:

    virtual ~PlayerSystem() {}

    virtual void configure(class World* world) override
    {

    }

    virtual void unconfigure(class World* world) override 
    {
        world->unsubscribeAll(this);
    }

    virtual void tick(class World* world, float deltaTime) override 
    {

        glm::vec3 direction = glm::vec3(0.0f);

        if (Input::keyPressed(KeyCode::W))
        {
            direction.z += -1.0f;
        }

        if (Input::keyPressed(KeyCode::S))
        {
            direction.z += 1.0f;
        }

        if (Input::keyPressed(KeyCode::A))
        {
            direction.x += -1.0f;
        }

        if (Input::keyPressed(KeyCode::D))
        {
            direction.x += 1.0f;
        }

        if (Input::mouseButtonDown(MouseButton::M_LEFT))
        {
            std::cout << "You clicked the left mouse button" << std::endl;
        }

        world->each<Transform, PlayerComponent, HealthComponent>([&](Entity* entity, 
                                                                        ComponentHandle<Transform> t, 
                                                                        ComponentHandle<PlayerComponent> pComp,
                                                                        ComponentHandle<HealthComponent> hComp) -> 
        void {

            t->Position += (direction * pComp->Speed) * deltaTime;

            hComp->Amount -= deltaTime * 0.1f;

        });
    }
};

int factorial(int n)
{
    int res = 1;

    for (int i = n; i > 1; i--)
    {
        res *= i;
    }

    return res;
}

int main(int argc, char** argv)
{
    Window window("AntisocialEngine", 800, 600);
    Input input;

    World* world = World::createWorld();

    Renderer renderer(world);

    world->registerSystem(new TestSystem());
    world->registerSystem(new TransformSystem());
    world->registerSystem(new PlayerSystem());

    std::vector<Vertex> vertices = {
        Vertex { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(1.0f, 1.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec2(1.0f, 1.0f) },
        Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 1.0f) },
        Vertex { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 1.0f) }    
    };

    std::vector<unsigned int> indices = {
        0,  1,  2,
        0,  2,  3,
        4,  5,  6,
        4,  6,  7,
        8,  9,  10,
        8,  10, 11,
        12, 13, 14,
        12, 14, 15,
        16, 17, 18,
        16, 18, 19,
        20, 21, 22,
        20, 22, 23
    };

    Entity* player = world->create();
    auto transform = player->assign<Transform>(glm::vec3(0.0f), glm::vec3(1.0f), glm::quat());
    auto playerComp = player->assign<PlayerComponent>(25.0f, 5.0f);
    auto healthComp = player->assign<HealthComponent>(100.0f);
    auto meshComp = player->assign<MeshComponent>(vertices, indices);

    for (int i = 0; i < 10000; i++)
    {
        Entity* ent = world->create();
        auto test = ent->assign<TestComp>(0.0f, 0.0f);

        if (i % 3 == 0)
        {
            auto trans = ent->assign<Transform>(glm::vec3(0.0f), glm::vec3(1.0f), glm::quat());
            auto tMatrix = ent->assign<TransformMatrix>(glm::mat4(1.0f));
        }
    }

    float previousTime = 0.0f;

    float deltaTime = 0.0f;
    float currentTime = 0.0f;

    while (!window.IsClosed())
    {
        currentTime     = glfwGetTime();
        deltaTime       = currentTime - previousTime;

        previousTime    = currentTime;
        
        OpenGL::Clear(0.1f, 0.1f, 0.1f, 1.0f);

        glfwPollEvents();

        world->tick(deltaTime);

        world->each<HealthComponent, Transform>([&](Entity* ent, ComponentHandle<HealthComponent> hComp, ComponentHandle<Transform> t) -> void {
            printf("Position is now: { %.2f, %.2f, %.2f }\n", t->Position.x, t->Position.y, t->Position.z);
            printf("Health value is now: %.4f\n", hComp->Amount);
        });

        window.Update();

        printf("FPS: %.2f\n", 1.0f / deltaTime);
    }

    world->destroyWorld();

    return 0;
}