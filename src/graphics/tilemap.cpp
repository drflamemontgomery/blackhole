/*
  Copyright (C) 2021, Ashton Warner
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 * \file tilemap.cpp
 *
 * A blackhole library class for turning tilemaps into images
 */

#include "graphics/tilemap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


namespace blackhole::graphics {
  
  Tilemap::Tilemap(const char* file, SDL_Renderer* renderer) {
    map = new Tmx::Map();
    map->ParseFile(file);
    
    tileLayers = (Image**)malloc(map->GetNumTileLayers()*sizeof(Image*));
    SpriteSheet** tilesets;
    tilesets = (SpriteSheet**)malloc(map->GetNumTilesets()*sizeof(SpriteSheet*));

    for(int i = 0; i < map->GetNumTilesets(); i++) {
      const Tmx::Image* tilesetImage = map->GetTileset(i)->GetImage();
      std::string tilesetFilepath = map->GetFilepath() + tilesetImage->GetSource();
      tilesets[i] = new SpriteSheet(tilesetFilepath.c_str(),
				    renderer, 0, 0,
				    map->GetTileset(i)->GetColumns(),
				    ceil(map->GetTileset(i)->GetTileCount()/
					 map->GetTileset(i)->GetColumns())
				    );
    }


    
    for(int i = 0; i < map->GetNumTileLayers(); i++) {

      const Tmx::TileLayer* layer = map->GetTileLayer(i);
      SDL_Texture* texture = SDL_CreateTexture(renderer,
					       SDL_PIXELFORMAT_RGBX8888,
					       SDL_TEXTUREACCESS_TARGET,
					       map->GetWidth()*
					       map->GetTileWidth(),
					       map->GetHeight()*
					       map->GetTileHeight());
      tileLayers[i] = new Image("/home/looking/c_testing/asdf.png", renderer, layer->GetX(), layer->GetY());
      

      SDL_Rect destrect = { 0, 0 , 0, 0 };

      SDL_SetRenderTarget(renderer, texture);
      
      for(int x = 0; x < layer->GetWidth(); x++) {
	for(int y = 0; y < layer->GetHeight(); y++) {
	  int tileset_id = layer->GetTileTilesetIndex(x, y);
	  tilesets[tileset_id]->setFrame(layer->GetTileId(x, y));

	  destrect = {
	    x*map->GetTileset(tileset_id)->GetTileWidth(),
	    y*map->GetTileset(tileset_id)->GetTileHeight(),
	    map->GetTileset(tileset_id)->GetTileWidth(),
	    map->GetTileset(tileset_id)->GetTileHeight()
	  };
	  SDL_RenderCopy(renderer, tilesets[tileset_id]->getTexture(),
			 tilesets[tileset_id]->getSrcRect(), &destrect);
	}
      }
      SDL_SetRenderTarget(renderer, NULL);
      printf("src_rect: %d\n", tileLayers[i]->getSrcRect() == NULL);
      
      tileLayers[i]->setTexture(texture);
      
    }
    

    free(tilesets);
    tilesets = 0;
  }

  Tilemap::~Tilemap() {
    free(tileLayers);
    tileLayers = 0;
  };

  
  Tmx::Map* Tilemap::getMap() {
    return map;
  }
  
  Image* Tilemap::getTileLayerImage(int layer) {
    return tileLayers[layer];
  }

  const Tmx::TileLayer* Tilemap::getTileLayer(int layer) {
    return map->GetTileLayer(layer);
  }
  
  const Tmx::ObjectGroup* Tilemap::getObjectGroup(int layer) {
    return map->GetObjectGroup(layer);
  }
}
