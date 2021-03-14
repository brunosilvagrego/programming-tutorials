import os
import pygame
from pygame.sprite import Sprite

current_directory = os.path.dirname(os.path.abspath(__file__))

class Ship(Sprite):
    """A class to manage the ship behavior."""

    def __init__(self, ai_settings, screen):
        """Initialize the ship and set its starting position."""
        # Inherit from Sprite
        super().__init__()

        self.ai_settings = ai_settings
        self.screen = screen

        # Load the ship image and get its rect
        ship_image_path = current_directory + '/images/ship.bmp'
        self.image = pygame.image.load(ship_image_path)

        # NOTE: One reason Pygame is so efficient is that it treats game
        # elements like rectangles (rects), even if they’re not exactly shaped
        # like rectangles.

        # Get the image surface’s rect attribute
        self.rect = self.image.get_rect()

        # Get the screen surface’s rect attribute
        self.screen_rect = screen.get_rect()

        # Start each new ship at the bottom center of the screen.
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

        # Store a decimal value for the ship's center.
        self.center = float(self.rect.centerx)

        # Movement flags
        self.moving_right = False
        self.moving_left = False

    def update(self):
        """Update the ship's position based on the movement flag."""
        # Right movement
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.center += self.ai_settings.ship_speed_factor

        # Left movement
        if self.moving_left and self.rect.left > 0:
            self.center -= self.ai_settings.ship_speed_factor

        # Update rect object from self.center
        self.rect.centerx = self.center

    def blitme(self):
        """Draw the ship at its current location."""
        self.screen.blit(self.image, self.rect)

    def center_ship(self):
        """Center the ship on the screen."""
        self.center = self.screen_rect.centerx
