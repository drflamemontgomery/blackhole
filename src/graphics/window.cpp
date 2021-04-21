#include "graphics/window.h"

namespace blackhole::graphics {

  bool compare_position(const ImageHolder& first, const ImageHolder& second);
  void renderThreadLoop(Window* window);
  void eventThreadLoop(Window* window);

  time_t getTime();
  
  Window::Window(int width, int height, const char* title) {
	this->width = width;
	this->height = height;
    this->title = title;
	this->bg_color = { 0xFF, 0xFF, 0xFF, 0xFF };
	
    init();
	
  }

  Window::Window(int width, int height, const char* title, Color bg) {
	this->width = width;
	this->height = height;
    this->title = title;
	this->bg_color = bg;

	init();
  }
  

  Window::~Window() {
	this->running = false;
	this->renderThread.join();
	this->eventThread.join();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
  }
  
  bool Window::init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	  printf("Failed to Initialize SDL2\n");
	  return false;
	}
	
	this->window = SDL_CreateWindow(this->title,
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									this->width,
									this->height,
									0);
	
	if(!this->window) {
	  printf("Failed to Initialize Window\n");
	  return false;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);

	if(!renderer) {
	  printf("Failed to Initialize Renderer\n");
	  return false;
	}
	return true;

	
  }

  // Rendering Function
  
  void Window::Render() {
	float time_dif;
	time_t time;
	while(running) {
	  time = getTime();
	  SDL_SetRenderDrawColor(renderer,
							 bg_color.red,
							 bg_color.green,
							 bg_color.blue,
							 bg_color.alpha);
	  SDL_RenderClear(renderer);
	  //SDL_Rect destr;
	  for(auto image = renderQueue.begin(); image != renderQueue.end(); ++image) {
		// SDL_QueryTexture(image->image->getTexture(), NULL, NULL,
		// 				 &destr.w, &destr.h);
		// destr.x = (int)image->image->getX();
		// destr.y = (int)image->image->getY();
		//SDL_RenderCopy(renderer, image->image->getTexture(), image->image->getSrcRect(), image->image->getDestRect());
		SDL_RenderCopyEx(renderer, image->image->getTexture(), image->image->getSrcRect(),image->image->getDestRect(), 0, NULL, image->image->getRendererFlip());
		image->image->addTime(time_dif);
		//SDL_RenderCopy(renderer, image->image->getTexture(), NULL, &destr);
	  }
	
	  SDL_RenderPresent(renderer);
	  while(difftime(getTime(), time) < 15.66) {
		SDL_Delay(1);
	  }
	  time_dif = difftime(getTime(), time)/1000;
	}
  }

  void Window::addImage(ImageBase* image, int position) {
	ImageHolder imageHolder = {
	  position,
	  image,
	};
    renderQueue.push_back(imageHolder);
	renderQueue.sort(compare_position);
  }
  
  int Window::getWidth() {
	return width;
  }

  int Window::getHeight() {
	return height;
  }

  SDL_Window* Window::getWindow() {
	return this->window;
  }

  SDL_Renderer* Window::getRenderer() {
	return this->renderer;
  }

  void Window::setScale(floatXY scale) {
	this->scale = scale;
    SDL_RenderSetScale(renderer, this->scale.x, this->scale.y);
  }

  floatXY Window::getScale() {;
	return scale;
  }

  void Window::startMainLoop(void (*_main)()) {
	this->running = true;
	this->renderThread = std::thread(renderThreadLoop, this);
	this->eventThread = std::thread(eventThreadLoop, this);
	this->_main = _main;
    time_t timer;
	while(!isClosed()) {
	  timer = getTime();
	  this->_main();
	  this->deltaTime = difftime(getTime(), timer)/1000.0;
	}
  }

  void Window::handleEvents() {
	while(running) {
	  SDL_Event event;
	  while(SDL_PollEvent(&event) && running) {
		switch(event.type) {
	    case SDL_WINDOWEVENT:
		  
		  switch(event.window.event) {
		  case SDL_WINDOWEVENT_CLOSE:
			closed = true;
		    return;
		  }
		  
		  break;
		}
	  }
	}
  }


  bool Window::isClosed() {
	return closed;
  }


  double Window::getDeltaTime() {
	return deltaTime;
  }
  
  bool Window::keyDown(SDL_Scancode scancode) {
	return keyboard_state[scancode];
  }

  bool Window::keyUp(SDL_Scancode scancode) {
	return !keyboard_state[scancode];
  }
  
  bool compare_position(const ImageHolder& first, const ImageHolder& second) {
	return(first.position < second.position);
  }

  void renderThreadLoop(Window* window) {
	window->Render();
  }

  void eventThreadLoop(Window* window) {
	window->handleEvents();
  }


  time_t getTime() {
	struct timeval time{};
	gettimeofday(&time, nullptr);
	time_t timer = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return timer;
  }
  
}
