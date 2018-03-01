class Result:
    def __init__(self):
        self.error = False
        self.message = ''

        self.sampler_name = ''
        self.measuring = False
        self.success = False

        self.sampling_interval = 0.0  # us
        self.average_interval = 0.0   # us
        self.average = []
        self.time_line = []

        self.mock_tau = 0.0

    def process(self):
        self.time_line = [self.average_interval * i for i in range(len(self.average))]
