class Hyperparameters:
    def __init__(self, k: int):
        self.k = k
        self.accuracy: float = None

    def calculate_accuracy(self, data):
        """Make call to calculate accuracy."""
        pass