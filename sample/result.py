import math


class Result:
    def __init__(self):
        self.error = False
        self.message = ''

        self.sampler_name = ''
        self.measuring = False
        self.success = False

        self.sampling_interval = 0.0  # us
        self.wave_interval = 0.0   # us
        self.wave = []
        self.time_line = []
        self.estimate = []

        self.tau = 0.0
        self.w = 0.0
        self.b = 0.0
        self.loss = 0.0

        self.v0 = 0.0
        self.v_inf = 0.0

        self.mock_tau = 0.0
        self.mock_v0 = 0.0
        self.mock_v_inf = 0.0

    def process(self):
        self.time_line = [self.wave_interval * i for i in range(len(self.wave))]

        if self.success:
            tau, w, b = self.tau, self.w, self.b
            self.estimate = [w * math.exp(t / -tau) + b for t in self.time_line]

            self.v0, self.v_inf = b + w, b
