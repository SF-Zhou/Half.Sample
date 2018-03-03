import unittest
from sample import sampler


class MyTestCase(unittest.TestCase):
    def test_sampler_set_get(self):
        result = sampler.communicate("set_sampler mock_sampler")
        self.assertEqual(result.sampler_name, "mock_sampler")

        result = sampler.communicate("get_sampler")
        self.assertEqual(result.sampler_name, "mock_sampler")

        try:
            result = sampler.communicate("set_sampler unknown_sampler")
        except sampler.Error as e:
            self.assertEqual(str(e), "sampler_not_found")

    def test_mock_tau_set_get(self):
        mock_tau = 100  # us
        result = sampler.communicate("set_mock_tau {}".format(mock_tau))
        self.assertEqual(result.mock_tau, mock_tau)

        result = sampler.communicate("get_mock_tau")
        self.assertEqual(result.mock_tau, mock_tau)

    def test_mock_voltage_set_get(self):
        mock_v0, mock_v_inf = 4.0, 6.0
        result = sampler.communicate("set_mock_voltage {} {}".format(mock_v0, mock_v_inf))
        self.assertEqual(result.mock_v0, mock_v0)
        self.assertEqual(result.mock_v_inf, mock_v_inf)

        result = sampler.communicate("get_mock_voltage")
        self.assertEqual(result.mock_v0, mock_v0)
        self.assertEqual(result.mock_v_inf, mock_v_inf)

        # recovery
        mock_v0, mock_v_inf = 2.5, 5.0
        result = sampler.communicate("set_mock_voltage {} {}".format(mock_v0, mock_v_inf))

    def test_mock_noise_set_get(self):
        mock_noise = 1.0  # V
        result = sampler.communicate("set_mock_noise {}".format(mock_noise))
        self.assertEqual(result.mock_noise, mock_noise)

        result = sampler.communicate("get_mock_noise")
        self.assertEqual(result.mock_noise, mock_noise)


if __name__ == '__main__':
    unittest.main()
