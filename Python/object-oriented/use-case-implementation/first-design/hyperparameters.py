import weakref


class Hyperparameters:
    """Hyperparameter class that represents k-parameter
    and associated accuracy.
    """

    def __init__(self, k: int, training: "TrainingData") -> None:
        self.k = k
        # Defined as forward reference because class
        # is not implemented yet
        self.data: weakref.ReferenceType["TrainingData"] = weakref.ref(training)
        self.accuracy: float

    def classify(self) -> str:
        pass

    def test(self):
        """Run test to assess Hyperparameter."""
        training_data = self.data()
        if not training_data:
            raise RuntimeError("Broken Weak Reference")

        correct, wrong = 0, 0

        for sample in training_data:
            sample.classification = self.classify(sample)
            if sample.matches():
                correct += 1
            else:
                wrong += 1

        self.accuracy = correct / (correct + wrong)
