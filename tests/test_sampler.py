import sample
import unittest


class MyTestCase(unittest.TestCase):
    sampler = sample.Sample()

    def test_commander_frame(self):
        result = self.sampler.communicate("get_sampler")
        self.assertEqual(result.sampler_name, "")

        result = self.sampler.communicate("set_sampler mock_sampler")
        self.assertEqual(result.sampler_name, "mock_sampler")

        result = self.sampler.communicate("get_sampler")
        self.assertEqual(result.sampler_name, "mock_sampler")


if __name__ == '__main__':
    unittest.main()
