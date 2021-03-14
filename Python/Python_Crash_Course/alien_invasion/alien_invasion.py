import pygame
from pygame.sprite import Group

import game_functions as gf
from settings import Settings
from ship import Ship
from game_stats import GameStats
from scoreboard import Scoreboard
from button import Button


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

    # Create a group to store bullets
    bullets = Group()

    # Create a group to store aliens
    aliens = Group()

    # Create the fleet of aliens
    gf.create_fleet(ai_settings, screen, ship, aliens)

    # Create an instance to store game statistics
    stats = GameStats(ai_settings)

    # Create an instance to store game scoreboard
    sb = Scoreboard(ai_settings, screen, stats)

    # Create the Play button
    play_button = Button(ai_settings, screen, "Play")

    # Start the main loop for the game
    while True:

        # Watch for keyboard and mouse events
        gf.check_events(ai_settings, screen, stats, sb, play_button, ship,
                        aliens, bullets)

        # Check if game objects should be updated
        if stats.game_active:
            # Update ship position
            ship.update()

            # Update bullets positions
            gf.update_bullets(ai_settings, screen, stats, sb, ship, aliens,
                              bullets)

            # Update aliens positions
            gf.update_aliens(ai_settings, screen, stats, sb, ship, aliens,
                             bullets)

        # Update screen
        gf.update_screen(ai_settings, screen, stats, sb, ship, aliens, bullets,
                         play_button)

# Start Game
run_game()
