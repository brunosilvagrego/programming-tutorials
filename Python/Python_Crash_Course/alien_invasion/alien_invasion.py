import pygame
from pygame.sprite import Group

import game_functions as gf
from settings import Settings
from ship import Ship

def run_game():
    """Initialize game and create a screen object."""

    # Initialize background settings
    pygame.init()

    # Create a display window
    ai_settings = Settings()
    screen = pygame.display.set_mode(
        (ai_settings.screen_width, ai_settings.screen_height))

    # Set Game Title
    pygame.display.set_caption("Alien Invasion")

    # Create a ship object
    ship = Ship(ai_settings, screen)

    # Make a group to store bullets in.
    bullets = Group()

    # Start the main loop for the game
    while True:

        # Watch for keyboard and mouse events
        gf.check_events(ai_settings, screen, ship, bullets)

        # Update ship position
        ship.update()

        # Update bullets positions
        gf.update_bullets(bullets)

        # Update screen
        gf.update_screen(ai_settings, screen, ship, bullets)

run_game()
