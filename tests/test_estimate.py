import time
import sample
import unittest


class MyTestCase(unittest.TestCase):
    sampler = sample.Sample()

    def test_estimate(self):
        self.sampler.set_sampler(sampler_name="mock_sampler")

        for mock_tau in [50, 100, 200]:  # us
            self.sampler.communicate("set_mock_tau {}".format(mock_tau))

            self.sampler.measure(number_of_waveforms=2, emitting_frequency=200)

            while self.sampler.is_measuring:
                time.sleep(0.1)

            result = self.sampler.query()
            self.assertEqual(result.success, True)

            tau = result.tau
            self.assertTrue(abs(tau - mock_tau) < 2.0)


if __name__ == '__main__':
    unittest.main()
