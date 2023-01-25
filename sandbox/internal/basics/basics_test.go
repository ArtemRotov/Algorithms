package basics

import "testing"

func TestSum(t *testing.T) {
	t.Run("easy", func(t *testing.T) {
		t.Parallel()
		t.Log("easy")
		var x, y, result = 2, 2, 4
		realResult := Sum(x, y)
		if realResult != result {
			t.Errorf("Bad value %d != good value %d", realResult, result)
		}
	})
}
