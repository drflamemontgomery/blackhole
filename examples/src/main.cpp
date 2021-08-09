#include <stdio.h>
#include <iostream>
#include <blackhole/graphics.h>
#include <box2d/box2d.h>

#define PTM_RATIO 64.0f

using namespace blackhole;

void game_main(void);


graphics::Window window(600, 600, "Test Window", {0, 0, 128, 128});
graphics::Camera camera1(window.getRenderer(), 600, 600, 0, 0);
graphics::SpriteSheet think_image("assets/Player_SpriteSheet.jpg", window.getRenderer(), 10, 10, 1, 5);

int think_anim0[4] = {0, 1, 2, 3};

int fps = 1;

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

  window.addImage(&think);
  window.addImage(tilemap.getTileLayerImage(0));
  window.addCamera(&camera1);

  window.setRenderFrame(tilemap.getMap()->GetWidth()*
			tilemap.getMap()->GetTileWidth(),
			tilemap.getMap()->GetHeight()*
			tilemap.getMap()->GetTileHeight());
  
  window.startMainLoop(game_main, 60);
  while(!window.isClosed());
  return 0;
}

float velX = 0;
float velY = 0;
float speed = 2*PTM_RATIO;

bool equals_pressed = false;
bool minus_pressed = false;



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
  world.Step(window.getDeltaTime(), 6, 2);
  
  think.setX(body->GetPosition().x);
  think.setY(body->GetPosition().y);

  camera1.getViewport()->x = -think.getX() + (int)(camera1.getViewport()->w/2);
}
