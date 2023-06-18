
## Quirks:
### Audio
We are not using `SDL_INIT_EVERYTHING` as SDL is struggling to connect to my audio drivers, therefore we instead specify the exact
services we want.
