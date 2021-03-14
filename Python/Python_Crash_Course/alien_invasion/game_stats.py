class GameStats():
    """Track statistics for Alien Invasion."""

    def __init__(self, ai_settings):
        """Initialize statistics."""
        self.ai_settings = ai_settings
        self.reset_stats()

        # Start Alien Invasion in an inactive state
        self.game_active = False

        # High score should never be reset
        self.high_score = 0

        # Initial game score
        self.score = 0

        # Initial difficulty level
        self.level = 1

    def reset_stats(self):
        """Initialize statistics that can change during the game."""
        # Initial number of ships
        self.ships_left = self.ai_settings.ship_limit

        # Initial game score
        self.score = 0

        # Initial difficulty level
        self.level = 1
