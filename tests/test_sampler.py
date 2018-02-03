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

    def test_is_measuring(self):
        result = self.sampler.communicate("is_measuring")
        self.assertEqual(result.measuring, False)

        result = self.sampler.communicate("to_measure 2 200")
        self.assertEqual(result.error, False)
        self.assertEqual(result.measuring, True)


if __name__ == '__main__':
    unittest.main()
