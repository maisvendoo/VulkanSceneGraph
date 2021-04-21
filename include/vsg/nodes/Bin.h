#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2018 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/maths/sphere.h>
#include <vsg/nodes/Node.h>

namespace vsg
{

    class VSG_DECLSPEC Bin : public Inherit<Node, Bin>
    {
    public:

        enum SortOrder
        {
            NO_SORT,
            ASCENDING,
            DESCENDING
        };

        Bin(Allocator* allocator = nullptr);
        Bin(uint32_t in_binNumber, SortOrder in_sortOrder, Allocator* allocator = nullptr);

        void traverse(RecordTraversal& visitor) const override;

        void read(Input& input) override;
        void write(Output& output) const override;

#if 1
        void add(double value, const Node* node);
#else
        inline void add(double value, const Node* node) { binElements.emplace_back(value, node); }
#endif

        uint32_t binNumber = 0;
        SortOrder sortOrder = NO_SORT;

        using KeyNode = std::pair<double, const Node*>;
        mutable std::vector<KeyNode> binElements;

    protected:
        virtual ~Bin();
    };
    VSG_type_name(vsg::Bin);

} // namespace vsg
