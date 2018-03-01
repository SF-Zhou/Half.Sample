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


if __name__ == '__main__':
    unittest.main()
