import sample
import unittest


class MyTestCase(unittest.TestCase):
    sampler = sample.Sample()

    def test_sampler_set_get(self):
        result = self.sampler.communicate("get_sampler")
        self.assertEqual(result.sampler_name, "")

        result = self.sampler.communicate("set_sampler mock_sampler")
        self.assertEqual(result.sampler_name, "mock_sampler")

        result = self.sampler.communicate("get_sampler")
        self.assertEqual(result.sampler_name, "mock_sampler")

        try:
            result = self.sampler.communicate("set_sampler unknown_sampler")
        except self.sampler.Error as e:
            self.assertEqual(str(e), "sampler_not_found")


if __name__ == '__main__':
    unittest.main()
