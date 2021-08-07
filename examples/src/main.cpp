#include <stdio.h>
#include <iostream>
#include <blackhole/graphics.h>
#include <box2d/box2d.h>

#define PTM_RATIO 64.0f

using namespace blackhole;

void game_main(void);


graphics::Window window(600, 600, "Test Window");
graphics::Camera camera1(window.getRenderer(), 300, 600, 0, 0);
graphics::Camera camera2(window.getRenderer(), 300, 600, 300, 0);
graphics::SpriteSheet think_image("assets/Player_SpriteSheet.jpg", window.getRenderer(), 10, 10, 1, 5);

int think_anim0[4] = {0, 1, 2, 3};

graphics::Animation think(&think_image, 0, think_anim0, 4, 0.2f);
graphics::Tilemap tilemap("assets/32_tilemap.tmx", window.getRenderer());

b2World world = b2World(b2Vec2(0.0f, 0.0f));

b2BodyDef bodyDef;


b2Body* body;

b2PolygonShape dynamicBox;


b2FixtureDef fixtureDef;

b2Fixture* fixture;

int main(int argc, char** argv) {
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(10.0f/PTM_RATIO, 20.0f/PTM_RATIO);

  body = world.CreateBody(&bodyDef);;
  body->SetFixedRotation(true);

  dynamicBox.SetAsBox(64.0f/PTM_RATIO, 64.0f/PTM_RATIO);

  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  fixtureDef.friction = 0.0f;
  fixtureDef.restitution = 0.0f;

  fixture = body->CreateFixture(&fixtureDef);

  think.setLayer(100);
  tilemap.getTileLayerImage(0)->setLayer(0);

  camera1.addImage(tilemap.getTileLayerImage(0));
  camera2.addImage(&think);

  camera2.addImage(tilemap.getTileLayerImage(0));
  camera1.addImage(&think);
  
  window.addImage(&camera1);
  window.addImage(&camera2);
  window.startMainLoop(game_main);
  while(!window.isClosed());
  return 0;
}

float velX = 0;
float velY = 0;
float speed = 1.0f;

void game_main(void) {
  if(window.keyDown(SDL_SCANCODE_LEFT)) {
    velX = -speed;
    velY = 0;
  }
  else if(window.keyDown(SDL_SCANCODE_RIGHT)) {
    velX = speed;
    velY = 0;
  }

  if(window.keyDown(SDL_SCANCODE_UP)) {
    velY = -speed;
    velX = 0;
  }
  else if(window.keyDown(SDL_SCANCODE_DOWN)) {
    velY = speed;
    velX = 0;
  }

  if(window.keyDown(SDL_SCANCODE_LSHIFT)) {
    velX = 0;
    velY = 0;
  }

  
  body->SetLinearVelocity(b2Vec2(velX, velY));
  world.Step(1.0f/60.0f, 6, 2);

  think.setX(body->GetPosition().x/PTM_RATIO);
  think.setY(body->GetPosition().y/PTM_RATIO);
}
