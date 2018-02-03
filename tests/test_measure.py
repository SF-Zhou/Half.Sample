import sample
import unittest


class MyTestCase(unittest.TestCase):
    sampler = sample.Sample()

    def test_is_measuring(self):
        result = self.sampler.communicate("is_measuring")
        self.assertEqual(result.measuring, False)

        result = self.sampler.communicate("to_measure 2 200")
        self.assertEqual(result.error, False)
        self.assertEqual(result.measuring, True)


if __name__ == '__main__':
    unittest.main()
