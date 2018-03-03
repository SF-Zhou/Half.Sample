import unittest
from sample import sampler


class MyTestCase(unittest.TestCase):
    def test_sampler_set_get(self):
        result = sampler.set_sampler(sampler_name="mock_sampler")
        self.assertEqual(result.sampler_name, "mock_sampler")

        result = sampler.get_sampler()
        self.assertEqual(result.sampler_name, "mock_sampler")

        try:
            result = sampler.communicate("set_sampler unknown_sampler")
        except sampler.Error as e:
            self.assertEqual(str(e), "sampler_not_found")

    def test_mock_tau_set_get(self):
        mock_tau = 100  # us
        result = sampler.set_sampler_value("mock_tau", mock_tau)
        self.assertEqual(result.mock_tau, mock_tau)

        result = sampler.get_sampler_value("mock_tau")
        self.assertEqual(result.mock_tau, mock_tau)

    def test_mock_voltage_set_get(self):
        mock_v0, mock_v_inf = 4.0, 6.0  # V
        result = sampler.set_sampler_value("mock_v0", mock_v0)
        self.assertEqual(result.mock_v0, mock_v0)

        result = sampler.set_sampler_value("mock_v_inf", mock_v_inf)
        self.assertEqual(result.mock_v_inf, mock_v_inf)

    def test_mock_noise_set_get(self):
        mock_noise = 1.0  # V
        result = sampler.set_sampler_value("mock_noise", mock_noise)
        self.assertEqual(result.mock_noise, mock_noise)

        result = sampler.get_sampler_value("mock_noise")
        self.assertEqual(result.mock_noise, mock_noise)


if __name__ == '__main__':
    unittest.main()
