import datetime
from hyperparameters import Hyperparameters
from sample import Sample
from typing import Dict, Iterable, List


class TrainingData:
    """Represents TrainingData and methods to load, test and classify it."""

    def __init__(self, name: str) -> None:
        self.name = name
        self.uploaded: datetime.datetime
        self.tested: datetime.datetime
        self.training: List[Sample] = []
        self.testing: List[Sample] = []
        self.tuning: List[Hyperparameters]

    def load(self, raw_data_source: Iterable[Dict[str, str]]) -> None:
        # Instead of opening and reading a file in this method, it is
        # better to abstract it out to not bind the class to a specific
        # file type. In this way details of the file format will be
        # isolated from details of managing the data
        self.uploaded = datetime.datetime.today()

    def test(self, hyperparameters: Hyperparameters) -> None:
        hyperparameters.test()
        self.tuning.append(hyperparameters)
        self.tested = datetime.datetime.today()

    def classify(self, hyperparameters: Hyperparameters, sample: Sample) -> None:
        classification = hyperparameters.classify(Sample)
        sample.classify(classification)
        return sample
