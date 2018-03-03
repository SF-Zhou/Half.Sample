import time
import unittest
from sample import sampler


class MyTestCase(unittest.TestCase):
    def test_estimate(self):
        sampler.set_sampler(sampler_name="mock_sampler")

        for mock_tau in [50, 100, 200]:  # us
            sampler.set_sampler_value("mock_tau", mock_tau)

            sampler.measure(number_of_waveforms=2, emitting_frequency=200)

            while sampler.is_measuring:
                time.sleep(0.1)

            result = sampler.query()
            self.assertEqual(result.success, True)

            tau = result.tau
            self.assertTrue(abs(tau - mock_tau) < 2.0)

    def test_auto_mode(self):
        sampler.set_sampler(sampler_name="mock_sampler")

        mock_taus = [1, 10, 100, 1000, 10000]  # us
        for mock_tau in mock_taus:
            sampler.set_sampler_value("mock_tau", mock_tau)
            sampler.measure(number_of_waveforms=4, emitting_frequency=10, auto_mode=True)
            while sampler.is_measuring:
                time.sleep(0.1)
            result = sampler.query()
            diff_ratio = abs(result.tau - mock_tau) / mock_tau

            self.assertTrue(diff_ratio <= 0.1 or diff < 0.5)

    def test_low_frequency(self):
        sampler.set_sampler(sampler_name="mock_sampler")

        mock_taus = [20000, 40000, 80000, 100000]  # us
        for mock_tau in mock_taus:
            sampler.set_sampler_value("mock_tau", mock_tau)

            sampler.measure(number_of_waveforms=4, emitting_frequency=10, auto_mode=True)
            while sampler.is_measuring:
                time.sleep(0.1)
            result = sampler.query()
            self.assertTrue(result.tau >= 10000)

            sampler.measure(number_of_waveforms=4, emitting_frequency=0.5, auto_mode=True)
            while sampler.is_measuring:
                time.sleep(0.1)
            result = sampler.query()
            diff_ratio = abs(result.tau - mock_tau) / mock_tau
            self.assertTrue(diff_ratio <= 0.01)  # less than 1%

    def test_low_voltage_margin(self):
        sampler.set_sampler(sampler_name="mock_sampler")

        for mock_v0, mock_v_inf in [[1, 2], [2, 3]]:
            sampler.set_sampler_value("mock_v0", mock_v0)
            sampler.set_sampler_value("mock_v_inf", mock_v_inf)

            mock_taus = [1, 10, 100, 1000, 10000]  # us
            for mock_tau in mock_taus:
                sampler.set_sampler_value("mock_tau", mock_tau)

                sampler.measure(number_of_waveforms=4, emitting_frequency=10, auto_mode=True)
                while sampler.is_measuring:
                    time.sleep(0.1)
                result = sampler.query()

                diff = abs(mock_tau - result.tau)
                diff_ratio = diff / mock_tau
                self.assertTrue(diff_ratio <= 0.2 or diff < 0.5)
                self.assertTrue(abs(mock_v0 - result.v0) <= 0.5)
                self.assertTrue(abs(mock_v_inf - result.v_inf) <= 0.5)


if __name__ == '__main__':
    unittest.main()
